#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<ctime>
#include<cassert>
#include<complex>
#include<string>
#include<cstring>
#include<chrono>
#include<random>
#include<bitset>

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long lox;
typedef long double lod;
typedef unsigned long long pox;
typedef pair<int, int> pii;

const int MAX_N = 2e5 + 5;

int n, a[MAX_N], nxt[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int first = n + 1;
	for (int i = n; i >= 1; --i) {
		nxt[i] = first;
		if (a[i] != 0) {
			first = i;
		}
	}
	lox ans = 0;
	for (int l = 1; l <= n; ++l) {
		vector<bool> used(21, 0);
		for (int r = l; r <= n; r = nxt[r]) {
			bool ok = true;
			for (int i = 0; i < 21; ++i) {
				if ((a[r] >> i) & 1) {
					if (used[i]) {
						ok = false;
						break;
					}
					used[i] = true;
				}
			}
			if (!ok) {
				break;
			}
			ans += (lox) (nxt[r] - r);
		}
	}
	cout << ans << "\n";
	return 0;
}