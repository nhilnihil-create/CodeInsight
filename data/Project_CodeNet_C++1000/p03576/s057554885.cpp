#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
ll INF = (1LL << 62) - 1;
int MOD = 1e9+7;
main(){
    int N,K;
    cin >> N >> K;
    vector<ll> X(N),Y(N);
    rep(i,0,N)cin >> X[i] >> Y[i];

    ll mini = INF;
    rep(i,0,N)rep(j,0,N)rep(k,0,N)rep(l,0,N){
        ll miniX = min({X[i], X[j], X[k], X[l]});
        ll maxiX = max({X[i], X[j], X[k], X[l]});
        ll miniY = min({Y[i], Y[j], Y[k], Y[l]});
        ll maxiY = max({Y[i], Y[j], Y[k], Y[l]});
        int cnt = 0;
        rep(m,0,N){
            if(X[m] >= miniX && X[m] <= maxiX && Y[m] >= miniY && Y[m] <= maxiY)cnt++;
        }
        if(cnt >= K){
            mini = min(mini, (maxiX - miniX) * (maxiY - miniY));
        }
    }
    cout << mini << endl;
}