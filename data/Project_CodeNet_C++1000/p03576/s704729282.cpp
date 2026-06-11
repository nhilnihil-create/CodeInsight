#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, K; cin >> N >> K;
	vector<pair<ll, ll>> po(N);
	for (int i = 0; i < N; i++) {
		cin >> po[i].first >> po[i].second;
	}

	sort(po.begin(), po.end());
	vector<vector<ll>> Y(N);
	ll ans = 4e18;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			Y[i].push_back(po[j].second);
			//printf("L[%d][%d]=%lld R[%d][%d]=%lld ", i, j, L[i][j], i, j, R[i][j]);
			if (j >= i + K - 1) {
				sort(Y[i].begin(), Y[i].end());
				for (int k = 0; k <= j - i - K + 1; k++) {
					ll temp = (po[j].first - po[i].first) * (Y[i][k + K - 1] - Y[i][k]);
					ans = min(ans, temp);
					//printf("i=%d j=%d k=%d temp=%lld\n", i, j, k, temp);
				}
			}
		}
		//cout << endl;
	}

	cout << ans << endl;
}
