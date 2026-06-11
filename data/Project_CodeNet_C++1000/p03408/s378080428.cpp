#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n, m, cnt = 0, ans = 0;
	cin >> n;
	vector<string> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s.at(i);
	}
	cin >> m;
	vector<string> t(m);
	for (int j = 0; j < m; j++) {
		cin >> t.at(j);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s.at(i) == s.at(j))cnt++;
		}
		for (int j = 0; j < m; j++) {
			if (s.at(i) == t.at(j))cnt--;
		}
		if (ans < cnt)ans = cnt;
		cnt = 0;
	}
	cout << ans << endl;
		return 0;
	}
