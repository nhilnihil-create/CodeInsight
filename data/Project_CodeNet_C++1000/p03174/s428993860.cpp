#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debarr(a,x,y)cerr<<#a<<":";for(int i=x;i<=y;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define deb(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S, class T>ostream &operator<<(ostream &os, const pair<S, T> &p) {return os << "(" << p.first << "," << p.second << ")";}
template<class T>ostream &operator<<(ostream &os, const vector<T> &p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const set<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const multiset<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class S, class T>ostream &operator<<(ostream &os, const map<S, T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>void dbs(string str, T t) {cerr << str << ":" << t << "\n";}
template<class T, class...S>void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << ":" << t << ","; dbs(str.substr(idx + 1), s...);}
#else
#define deb(...){}
#define debarr(a,x,y){}
#define debmat(mat,row,col){}
#endif

#define int              long long
#define fi               first
#define se               second
#define mp               make_pair
#define pb               push_back
#define rr               return
#define sz(x)            (int)x.size()
#define all(x)           x.begin(),x.end()
#define ini(x,y)         memset(x,y,sizeof(x))
#define rep(i,n)         for(int i=0;i<n;i++)
#define fr(i,a,b)        for(int i=a;i<=b;i++)
#define fb(i,a,b)        for(int i=a;i>=b;i--)

typedef pair<int, int>   pii;
typedef vector<int>      vi;
typedef vector<pii>      vii;

const int inf = 4e18;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n;
int a[25][25];
int dp[22][1 << 22];

int go(int idx, int mask)
{
	if (idx == n) return (mask == 0);
	if (dp[idx][mask] != -1) return dp[idx][mask];
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[idx][i] && (mask & (1 << i)))
		{
			ret = (ret + go(idx + 1, mask ^ (1 << i))) % mod;
		}
	}
	return dp[idx][mask] = ret;
}
void solve()
{
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j];
	ini(dp, -1);
	cout << go(0, (1 << n) - 1);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}