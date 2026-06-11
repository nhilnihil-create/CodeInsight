#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

ll gcd(ll x, ll y){ return y? gcd(y, x%y): x; }
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	VI a(m);
	rep(i, m) cin >>a[i];
	const VI kt = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<string> dp(n+2);
	sort(a.rbegin(), a.rend());

	rep(i, m) rep(j, n) if(j==0 || sz(dp[j])){
		int su = j+kt[a[i]];
		string ns = dp[j]+ to_string(a[i]);
		if(su > n) continue;
		if((sz(dp[su]) < sz(ns))||(sz(dp[su])<=sz(ns) && ns > dp[su])) dp[su] = ns;
	}
	cout <<dp[n] <<"\n";
	//for(auto x :dp) cerr<<x<<" "; dbg();
	return 0;
}
