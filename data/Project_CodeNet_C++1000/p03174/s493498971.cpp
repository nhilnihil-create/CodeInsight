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
ll MOD = 1e9+7;

int n;
bool a[22][22];
bool women[22];

int done[(1<<22)];

int base = 0;
ll pairs(int now){
    if(now == n) return 1;
    if(done[base] >= 0) return done[base];
    ll ans = 0;
    for(int j=0;j<n;++j){
        if(a[now][j] && !women[j]){
            women[j] = 1;
            base += 1<<j;
            ans += pairs(now+1);
            women[j] = 0;
            base -= 1<<j;
            if(ans >= MOD) ans-=MOD;
        }
    }
    done[base] = ans;
    //dbg(now); dbg(ans); dbgA(women, n); cerr<<endl;
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    fastio();
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            int x;
            cin>>x;
            a[i][j] = x==1;
        }
    memset(done, -1, sizeof(done));
    cout<<pairs(0);
    return 0;
}
