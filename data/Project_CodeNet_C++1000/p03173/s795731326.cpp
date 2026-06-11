/******************************************
* AUTHOR : HRITIK AGGARWAL *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define inf 1000000000000007
#define dd double
#define vi vector<int>
#define vll vector<ll>
#define forr(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define int ll
ll po(ll a, ll x, ll m) { if (x == 0) {return 1;} ll ans = 1; ll k = 1;  while (k <= x) {if (x & k) {ans = ((ans * a) % m);} k <<= 1; a *= a; a %= m; } return ans; }
// DEKHIYE JI  WALID JO THE ABBA HAMARE WO YEH function CHHOD KR GYE THE
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int a[n];
	forr(i, n) {
		cin >> a[i];
	}
	int pref[n + 1];
	pref[0] = 0;
	forr(i, n) {
		pref[i + 1] = pref[i] + a[i];
	}
	int mat[n][n];
	ms(mat, 0);
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n - k + 1; i++) {
			int j = i + k - 1;
			mat[i][j] = inf;
			for (int x = i; x < j; x++) {
				mat[i][j] = min(mat[i][j], mat[i][x] + mat[x + 1][j]);
			}
			mat[i][j] += (pref[j + 1] - pref[i]);
		}
	}
	cout << mat[0][n - 1] << "\n";
	return 0;
}