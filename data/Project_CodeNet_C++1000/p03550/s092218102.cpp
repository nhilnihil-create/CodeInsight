#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
ll INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    ll N,Z,W;
    cin >> N >> Z >> W;
    vector<ll> V(N);

    rep(i,0,N)cin >> V[i];
    if(N == 1){
        cout << abs(V[0] - W) << endl;
        return 0;
    }
    ll ans = max(abs(V[N-1] - W), abs(V[N-2] - V[N-1]));
    cout << ans << endl;
}