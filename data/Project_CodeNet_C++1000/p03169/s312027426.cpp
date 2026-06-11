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

double dp[301][301][301];
int n;

double solve(int x, int y, int z){
    if(x<0 || y<0 || z<0) return 0;
    if(x==0 && y==0 && z==0) return 0;
    if(dp[x][y][z] > 0) return dp[x][y][z];
    double probx = (double)x/n;
    double proby = (double)y/n;
    double probz = (double)z/n;
    double prob0 = 1-(probx+proby+probz);
    dp[x][y][z] = (1+probx*solve(x-1,y,z)+proby*solve(x+1,y-1,z)+probz*solve(x,y+1,z-1))/(1-prob0);
    return dp[x][y][z];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    fastio();
    setPrecision(10);
    cin>>n;
    int x,y,z;
    x=y=z=0;
    for(int i=0;i<n;++i){
        int temp; cin>>temp;
        x += temp==1;
        y += temp==2;
        z += temp==3;
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(x,y,z);
    return 0;
}
