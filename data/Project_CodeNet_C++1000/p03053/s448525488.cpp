/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/05/06 09:02:48 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

/* #include <boost/multi_array.hpp> */
/* #include <boost/optional.hpp> */
/* #include <boost/range/irange.hpp> */
/* #include <boost/range/algorithm.hpp> */
/* #include <boost/range/adaptors.hpp> */
/* #include <boost/multiprecision/cpp_int.hpp> */
/* #include <boost/algorithm/string/classification.hpp> // is_any_of */
/* #include <boost/algorithm/string/split.hpp> */
/* #include <boost/algorithm/string/join.hpp> */
/* #include <boost/algorithm/string/replace.hpp> */
/* #include <boost/math/tools/minima.hpp> */
/* namespace adaptor = boost::adaptors; */
/* using boost::math::tools::brent_find_minima; */
/* using boost::irange; */
/* using boost::algorithm::join; */
/* using boost::algorithm::split; */
/* using boost::algorithm::replace_all; */
/* using boost::multiprecision::cpp_int; */

using namespace std;

#define	int	long long
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

typedef long long 			ll;
typedef vector<int>			VI;
typedef vector<vector<int>>	VVI;
typedef pair<int, int>		PII;

// TOP
int				h, w;
vector<string>	field;
const int		dy[4] = {0, 1, 0, -1};
const int		dx[4] = {1, 0, -1, 0};

void	Main()
{
	cin >> h >> w;

	field.resize(h);
	rep(i, h)
		cin >> field[i];
	queue<PII>	que;
	rep(y, h)
	{
		rep(x, w)
		{
			if (field[y][x] == '#')
				que.push(PII(y, x));
		}
	}
	que.push(PII(h, w));
	int	count;

	count = 0;
	while (que.size() > 1)
	{
		int y, x;

		y = que.front().first;
		x = que.front().second;
		que.pop();
		if (y == h && x == w)
		{
			count++;
			que.push(PII(h, w));
			continue;
		}
		rep(dir, 4)
		{
			int ny, nx;

			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)
				continue;
			if (field[ny][nx] == '#')
				continue;
			field[ny][nx] = '#';
			que.push(PII(ny, nx));
		}
	}
	cout << count << endl;
}
// END

int32_t	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
