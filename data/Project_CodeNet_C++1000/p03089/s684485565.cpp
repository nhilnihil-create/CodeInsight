/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/28 06:06:21 by monoue           ###   ########.fr       */
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

#define MOD 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	int	n;
	cin >> n;

	vector<int>	V(n);
	stack<int>	S;
	rep(i, n)
		cin >> V.at(i);
	int	current_size;
	current_size = n;
	while (current_size)
	{
		int check;
		check = current_size;
		bool	flag;
		flag = false;
		rrep(i, n - 1)
		{
			if (V.at(i) == 0)
				continue;
			else if (V.at(i) == check)
			{
				S.push(V.at(i));
				V.at(i) = 0;
				current_size--;
				flag = true;
				break;
			}
			else
				check--;
		}
		if (flag == false)
		{
			cout << -1 << endl;
			return ;
		}
	}
	rep(i, n)
	{
		cout << S.top() << endl;
		S.pop();
	}
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
