/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc109_c.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkinoshi <nkinoshi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:22:56 by nkinoshi          #+#    #+#             */
/*   Updated: 2020/07/28 22:25:42 by nkinoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

ll	gcd(ll a, ll b)
{
	if (b > 0)
		gcd(b, a % b);
	return (a);
}

int		main(void)
{
	int n, x;
	cin >> n >> x;

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		ans = gcd(ans, abs(x - a));
	}
	cout << ans << endl;
}
