//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18 + 69;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n;
char mat[650][650];
ll count(ll x, ll y) {// count on diagonal
	ll bad = 0, cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			bad += mat[i+x][j+y]!=mat[j+x][i+y];
	cnt += (bad == 0);
	while(x+1<n&&y+1<n) {
		for(int i = 0; i < n; i++)
			bad -= mat[x][y+i]!=mat[x+i][y];
		for(int i = 0; i < n; i++)
			bad += mat[x+n][y+i]!=mat[x+i][y+n];
		++x, ++y;
		cnt += (bad == 0);
	}
	return cnt;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
			mat[n+i][n+j]=mat[n+i][j]=mat[i][n+j]=mat[i][j];
		}
	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += count(0, i);
	for(int i = 1; i < n; i++)
		ans += count(i, 0);
	cout << ans;
}
