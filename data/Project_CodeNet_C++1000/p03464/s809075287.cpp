#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int K; cin >> K;
	vector<ll> a(K);
	for (int i = 0; i < K; i++) {
		cin >> a[i];
	}
	bool flag = true;
	vector<pair<ll, ll>> p(K);
	p[K - 1].first = 2, p[K - 1].second = 2;
	for (int i = K - 1; i >= 1; i--) {
		p[i - 1].first = a[i - 1] * ((p[i].first + a[i - 1] - 1) / a[i - 1]);
		p[i - 1].second = a[i - 1] * ((p[i].second + a[i] - 1) / a[i - 1]);
		//cout << "i-1=" << i-1 << " " << p[i-1].first << " " << p[i-1].second << endl;
		if (!(p[i].first <= p[i-1].first || p[i - 1].second <= p[i].second)||p[i-1].first>p[i-1].second) {
			flag = false;
			break;
		}
		
	}
	if (flag&&a[K-1]==2) {
		ll mn = 0, mx = 0;
		mn = p[0].first;
		mx = p[0].second + a[0] - 1;
		cout << mn << " " << mx << endl;
	}
	else cout << -1 << endl;
}
