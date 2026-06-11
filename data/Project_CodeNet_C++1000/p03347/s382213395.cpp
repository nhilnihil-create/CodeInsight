#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	bool flag = true;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] > i) flag = false;
		if (i > 0 && a[i - 1] + 1 < a[i]) flag = false;

	}
	if (!flag) cout << -1 << endl;
	else {
		ll ans = 0;
		for (int i = 1; i < N; i++) {
			if (a[i - 1] + 1 == a[i]) ans++;
			else ans += a[i];
		}
		cout << ans << endl;
	}
}