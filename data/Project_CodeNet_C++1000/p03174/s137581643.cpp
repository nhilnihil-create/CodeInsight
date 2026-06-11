# include "bits/stdc++.h"

using namespace std;

#define endl "\n"
typedef long long ll;

#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
inline void setPrecision(int n){cout.precision(n);}

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
        if(a[idx][i] && !(state&(1<<i)))
            ans = (ans + pairs(state|(1<<i)))%MOD;
    done[state] = ans;
    return ans;
}

int main(){
    fastio;
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];
    memset(done, -1, sizeof(done));
    cout<<pairs(0);
    return 0;
}
