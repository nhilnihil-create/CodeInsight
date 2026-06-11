#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
int test[345678], cnt[345678], visit[345678];
const int INF = 10000000000000;
signed main() {
	int n, m, q; cin >> n >> m >> q;
	for (int h = 0; h < n; h++) {
		cin >> test[h];
	}
	for (int h = 0; h < m; h++) {
		cin >> cnt[h];
	}
	for (int h = 0; h < q; h++) {
		cin >> visit[h];
		int b = lower_bound(test, test + n, visit[h]) - test - 1;
		int c = lower_bound(test, test + n, visit[h]) - test;
		if (test[c] == 0) { b = abs(test[b] - visit[h]); c = INF; }
		else if (test[b] == 0) { b = INF; c = abs(test[c] - visit[h]); }
		else { b = abs(test[b] - visit[h]); c = abs(test[c] - visit[h]); }
		int e = lower_bound(cnt, cnt + m, visit[h]) - cnt - 1;
		int f = lower_bound(cnt, cnt + m, visit[h]) - cnt;
		if (cnt[f] == 0) { e = abs(cnt[e] - visit[h]); f = INF; }
		else if (cnt[e] == 0) { e = INF; f = abs(cnt[f] - visit[h]); }
		else { e = abs(cnt[e] - visit[h]); f = abs(cnt[f] - visit[h]); }
		int a = min(min(b, f) + min(b, f) + max(b, f), min(c, e) + min(c, e) + max(c, e));
		int d = min(max(b, e), max(c, f));
		cout << min(a, d) << endl;
	}

}