# include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int ll;

inline void fastio(){ios::sync_with_stdio(false); cin.tie(0);}
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
ll MOD = 1e9+7;

int n;
int a[21][21];

ll done[1<<21];

ll pairs(int state){
    int idx = __builtin_popcount(state);
    if(idx == n) return 1;
    if(done[state] != -1) return done[state];
    ll ans = 0;
    for(int i=0;i<n;++i)
        if(a[idx][i] && !(state&(1<<i))){
            ans = (ans + pairs(state|(1<<i)))%MOD;
        }
    done[state] = ans;
    return ans;
}

int main(){
    fastio();
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];
    memset(done, -1, sizeof(done));
    cout<<pairs(0);
    return 0;
}
