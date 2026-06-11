// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define exf(x)	 for(auto&& tmp : x) { cout << tmp << endl; }	// 拡張for
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int N, M; cin >> N >> M;
	int s[10][10] = { 0 };
	rep(i, M) {
		int k; cin >> k;
		rep(j, k) cin >> s[i][j];
	}
	vector<int> p(M);
	rep(i, M) cin >> p[i];

	int ans = 0;
	rep(bit, 1 << N) {
		bool F = true;
		rep(i, M) {
			int t = 0;
			rep(j, M) {
				int tmp = s[i][j];
				if (tmp == 0) break;
				if (bit & (1 << (tmp - 1))) t++;
			}
			if (t % 2 != p[i]) {
				F = false;
				break;
			}
		}
		ans = (F ? ans + 1 : ans);
	}

	cout << ans << endl;
	return 0;
}
