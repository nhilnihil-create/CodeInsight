/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/29 15:35:56 by monoue           ###   ########.fr       */
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
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	int	n;
	cin >> n;
	vector<int>	O(100001);
	vector<int>	E(100001);
	set<int>	OS;
	set<int>	ES;
	rep(i, n)
	{
		int	x;
		cin >> x;
		if (i % 2)
		{
			O.at(x)++;
			OS.insert(x);
		}
		else
		{
			E.at(x)++;
			ES.insert(x);
		}
	}
	int	maxocnt, smaxocnt, maxecnt, smaxecnt, maxoi, smaxoi, maxei, smaxei;
	maxocnt = smaxocnt = maxecnt = smaxecnt = INT_MIN;
	maxoi = smaxoi = maxei = smaxei = -1;
	rep(i, 100001)
	{
		if (O.at(i) > maxocnt)
		{
			maxocnt = O.at(i);
			maxoi = i;
		}
		if (E.at(i) > maxecnt)
		{
			maxecnt = E.at(i);
			maxei = i;
		}
	}
	rep(i, 100001)
	{
		if (i != maxoi && O.at(i) > smaxocnt)
		{
			smaxocnt = O.at(i);
			smaxoi = i;
		}
		if (i != maxei && E.at(i) > smaxecnt)
		{
			smaxecnt = E.at(i);
			smaxei = i;
		}
	}
	if (OS.size() == 1 && ES.size() == 1)
	{
		if (maxoi == maxei)
			cout << n / 2 << endl;
		else
			cout << 0 << endl;
		return ;
	}
	if ((OS.size() == 1 || ES.size() == 1) && maxoi == maxei)
	{
		if (OS.size() == 1)
			cout << n / 2 - smaxecnt << endl;
		else
			cout << n / 2 - smaxocnt << endl;
		return ;
	}
	if (maxoi == maxei)
	{
		if (maxecnt + smaxocnt > maxocnt + smaxecnt)
			cout << n - (maxecnt + smaxocnt) << endl;
		else
			cout << n - (maxocnt + smaxecnt) << endl;
		return ;
		// if (((n / 2 - smaxecnt) + (n / 2 - maxocnt)) < ((n / 2 - smaxocnt) + (n / 2 - maxecnt)))
		// 	cout << (n / 2 - smaxecnt) + (n / 2 - maxocnt) << endl;
		// else
		// 	cout << (n / 2 - smaxocnt) + (n / 2 - maxecnt) << endl;
		// return ;
	}
	cout << (n / 2 - maxocnt) + (n / 2 - maxecnt) << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
