#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    ll N, M;
    ll ans = 0;
    cin >> N >> M;
    vector<ll> X(M);
    vector<ll> XD(M-1,0);
    
    rep(i, 0, M){
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    rep(i, 0, M-1){
        ll tmp = X[i+1]-X[i];
        XD[i] = tmp;
    }
    sort(XD.begin(), XD.end());
    rep(i, 0, M-N){
        ans += XD[i];
    }
    cout << ans << endl;
    return 0;
}
