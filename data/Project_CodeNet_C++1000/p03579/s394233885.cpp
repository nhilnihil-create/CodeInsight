/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/05/06 07:32:23 by monoue           ###   ########.fr       */
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
int n, m;

VVI	G;
VI	color;

bool	dfs(int v, int cur = 0)
{
	color[v] = cur;
	for (auto next_v : G[v])
	{
		if (color[next_v] != -1)
		{
			if (color[next_v] == cur)
				return (false);
			continue;
		}
		if (!dfs(next_v, 1 - cur))
			return (false);
	}
	return (true);
}

void	Main()
{
	cin >> n >> m;

	G.resize(n);
	color.assign(n, -1);
	rep(v, m)
	{
		int a, b; cin >> a >> b;

		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool	is_bipartite;

	is_bipartite = true;
	if (!dfs(0))
		is_bipartite = false;
	if (is_bipartite)
	{
		int w, b;

		w = 0;
		b = 0;
		rep(v, n)
		{
			if (color[v] == 0)
				w++;
			else
				b++;
		}
		cout << w * b - m << endl;
	}
	else
		cout << n * (n - 1) / 2 - m << endl;
}
// END

int32_t	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
