/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:57:35 by thbernar          #+#    #+#             */
/*   Updated: 2017/12/05 16:59:54 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

void	ft_read_fd(const int fd, char **s);

int		get_next_line(const int fd, char **line)
{
	char *s;
	s = (char*)malloc(sizeof(s));
	ft_read_fd(fd, &s);
	printf("%s\n", s);
	return (0);
}

void	ft_read_fd(const int fd, char **s)
{
	char buff[BUFF_SIZE + 1];
	int ret;
	char *p_s;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		p_s = *s;
		buff[ret] = 0;
		*s = ft_strjoin(*s, buff);
		free(p_s);
	}
}

int main (void)
{
	int fd;
	char buf[128];
	char s[1024];
	char *p_s;
	p_s = s;
	fd = open("sample", O_RDONLY);
	if (fd == -1)
		return (-1);
	//get_next_line((const int)fd, &p_s);
	return (0);
}
