#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	map<ll, int> mp1;
	map<ll, int> mp2;
	rep(i, n) {
		int a; cin >> a;
		mp1[a]++;
	}
	cin >> m;
	rep(i, m) {
		int a; cin >> a;
		mp2[a]++;
	}
	bool elf = true;
	for (auto& c : mp2) {
		if (mp1[c.first] < c.second) elf = false;
	}
	dunk(elf ? "YES" : "NO");
	return 0;
}
