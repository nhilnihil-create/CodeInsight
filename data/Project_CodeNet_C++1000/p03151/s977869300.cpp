/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/28 14:40:18 by monoue           ###   ########.fr       */
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
	ll	n;
	cin >> n;
	vector<ll>	A(n);
	vector<ll>	B(n);
	vector<ll>	C(n);
	vector<ll>	D;
	rep(i, n)
		cin >> A.at(i);
	rep(i, n)
		cin >> B.at(i);
	// if (accumulate(A.begin(), A.end(), 0LL) < accumulate(B.begin(), B.end(), 0LL))
	// ll	sum;
	// sum = 0;
	rep(i, n)
		C.at(i) = B.at(i) - A.at(i);
	sort(C.begin(), C.end());
	if (C.at(n - 1) <= 0)
	{
		cout << 0 << endl;
		return ;
	}
	if (accumulate(C.begin(), C.end(), 0LL) > 0)
	{
		cout << -1 << endl;
		return ;
	}
	ll	sum;
	sum = 0;
	// rrep(i, n - 1)
	// {
	// 	if (C.at(i) < 0)
	// 	{
	// 		D.push_back(abs(C.at(i)) + sum);
	// 		sum += abs(C.at(i));
	// 	}
	// }
	rep(i, n)
	{
		if (C.at(i) >= 0)
			break ;
		D.push_back(abs(C.at(i)) + sum);
		sum = D.at(i);
	}
	sum = 0;
	ll	lack;
	lack = 0;
	rrep(i, n - 1)
	{
		if (C.at(i) <= 0)
			break ;
		sum += C.at(i);
		lack++;
	}
	int	i;
	i = lower_bound(D.begin(), D.end(), sum) - D.begin() + 1;
	cout << i + lack << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
