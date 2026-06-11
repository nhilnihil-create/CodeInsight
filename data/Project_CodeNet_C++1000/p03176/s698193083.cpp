# include "bits/stdc++.h"

using namespace std;

#define endl "\n"
typedef long long int ll;

inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
inline void setPrecision(int n){cout.precision(n);}

//DEBUG
#define dbg(x) cerr<<(#x)<<": "<<x<<endl
#define dbgV(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgS(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgM(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
#define dbg2D(x) cerr<<(#x)<<": \n"; for(auto y: x) { for(auto it: y) cerr<<it<<" "; cerr<<endl; } cerr<<endl;
#define dbgA(x, n) cerr<<(#x)<<": "; for(int i=0;i<n;++i) cerr<<x[i]<<" "; cerr<<endl;
#define dbgVP(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;

ll INF = 1e10;
int MOD = 1e9+7;

const int mxn = 2e5 + 5;
int h[mxn], b[mxn];
int n;
ll dp[mxn];
ll val[mxn];

ll t[4*mxn] = {0}; //segtree

void update(int cur, int tl, int tr, int idx, ll num){
	if(tl == tr) t[cur] = val[idx] = num;
	else{
		int tm = (tl+tr)>>1;
		if(idx <= tm) update(2*cur+1, tl, tm, idx, num);
		else update(2*cur+2, tm+1, tr, idx, num);
		t[cur] = max(t[2*cur+1], t[2*cur+2]);
	}
}

ll query(int cur, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(tl == l && tr == r) return t[cur];
	int tm = (tl+tr)>>1;
	if(r <= tm) return query(2*cur+1, tl, tm, l, r);
	else if(l > tm) return query(2*cur+2, tm+1, tr, l, r);
	else return max(query(2*cur+1, tl, tm, l, tm), query(2*cur+2, tm+1, tr, tm+1, r));
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    fastio();
    cin>>n;
    for(int i=0;i<n;++i) {cin>>h[i]; h[i]-=1;}
    for(int i=0;i<n;++i) cin>>b[i];
    //dp[i] max beauty if ith is last element
    dp[0] = b[0];
	update(0, 0, n-1, h[0], dp[0]);
	ll ans = dp[0];
	for(int i=1;i<n;++i){
		dp[i] = query(0, 0, n-1, 0, h[i]-1) + (ll)b[i];
		update(0, 0, n-1, h[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout<<ans;
    return 0;
}
