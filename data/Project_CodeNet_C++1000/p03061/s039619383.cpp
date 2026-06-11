/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc125_c.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkinoshi <nkinoshi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 23:44:44 by nkinoshi          #+#    #+#             */
/*   Updated: 2020/07/31 23:52:49 by nkinoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		gcd(int a, int b)
{
	if (b > 0)
		return (gcd(b, a % b));
	else
		return (a);
}

int		main(void)
{
	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	
	vector<int> L(n+1);
	vector<int> R(n+1);
	for (int i = 0; i < n; ++i)
		L[i+1] = gcd(L[i], A[i]);
	for (int i = n-1; i >= 0; --i)
		R[i] = gcd(R[i+1], A[i]);
	
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, gcd(L[i], R[i+1]));

	// for (int i = 0; i < n; ++i)
	// 	cout << L[i] << ", ";
	// cout << endl;
	// for (int i = 0; i < n; ++i)
	// 	cout << R[i] << ", ";
	// cout << endl;

	cout << ans << endl;
}

