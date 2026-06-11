#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const ll powll = 1LL<<1;

int main(void){
    int n,t; cin >> n >> t;
    int ans = MOD;
    rep(i,0,n){
        int c,tt; cin >> c >> tt;
        if(tt <= t){
            ans = min(ans,c);
        }
    }
    if(ans == MOD) cout << "TLE\n";
    else cout << ans << "\n";
}