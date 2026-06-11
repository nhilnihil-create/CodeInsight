#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;

using ll = long long; using VI=vector<int>; using pii=pair<int, int>; using VL=vector<ll>; const int MD=1e9+7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	cin >>n >>k;
	VL a(n), dp(k+2);
	rep(i, n) cin >>a[i];
	dp[0] = 1;
	
	rep(i, n){
		VL np(k+2), sum(k+3, 0);
		rep(j, k+1) sum[j+1] = (dp[j] + sum[j]) %MD;
		rep(j, k+1) np[j] = (sum[j+1] - sum[max(0LL, j-a[i])] + MD ) %MD;
		swap(dp, np);
	}
	cout <<dp[k] <<"\n";
	return 0;
}

