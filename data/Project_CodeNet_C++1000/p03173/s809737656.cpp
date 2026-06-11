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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    fastio();
    int n;
    vector<int> a;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;++i) cin>>a[i];
    
    ll dp[n][n]; //min cost to merge l to r
    
    for(int len = 1; len <= n; ++len){
        for(int i=0;i<=n-len;++i){
            if(len == 1) dp[i][i] = 0;
            else{
                int l = i;
                int r = i+len-1;
                dp[l][r] = 1e18;
                ll sum = 0;
                for(int i=l;i<=r;++i) sum += a[i];
                for(int p = l; p < r; ++p)
                    dp[l][r] = min(dp[l][r], dp[l][p] + dp[p+1][r] + sum);
            }
        }
    }

    cout<<dp[0][n-1];
    return 0;
}
