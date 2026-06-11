#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;

	vector<ll> a(N), b(N);
	ll suma = 0, sumb = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		suma += a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
		sumb += b[i];
	}

	ll K = sumb - suma;
	ll cnta = 0, cntb = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] < b[i]) {
			ll temp = (b[i] - a[i] + 1) / 2;
			cnta +=  temp;
			a[i] += 2 * temp;
			cntb += a[i] - b[i];
			b[i] = a[i];
		}

		else {
			cntb += a[i] - b[i];
			b[i] = a[i];
		}
	}

	if (cnta <= K && cntb <= K && 2 * (K - cnta) == (K - cntb))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}