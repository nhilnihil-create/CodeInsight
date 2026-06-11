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
		VL np(k+2);
		rep(j, k+1){
			np[j] = (dp[j] + (j>=1? np[j-1]: 0)) %MD;
			if(j>=a[i]+1) (np[j] += MD - dp[j-a[i]-1]) %=MD;
		}
		swap(np, dp);
	}
	cout <<dp[k] <<"\n";
	
	return 0;
}

