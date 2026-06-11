#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> X(M);
    rep(i,M){
        cin >> X[i];
    }
    sort(X.begin(),X.end());
    vector<ll> dif;
    rep(i,M-1){
        dif.push_back(X[i+1]-X[i]);
    }
    sort(dif.begin(),dif.end());
    // N-1箇所の区間を通らなくて済む
    // 小さい区間をM-1-(N-1)個通る
    ll ans = 0;
    rep(i,M-N){
        ans += dif[i];
    }
    cout << ans << endl;
    return 0;
}