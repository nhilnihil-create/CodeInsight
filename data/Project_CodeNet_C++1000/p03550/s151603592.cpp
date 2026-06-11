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
	ll N, Z, W; cin >> N >> Z >> W;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	if (N == 1) cout << abs(a[0] - W) << endl;
	else cout << max(abs(a[N - 1] - W), abs(a[N - 1] - a[N - 2]));
	
}