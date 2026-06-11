#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;

//素数判定
bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int main() {
    ll N, M, M_; cin >> N >> M;
    if(N == 1){
        cout << M << endl;
        return 0;
    }
    M_ = M;
    vector<ll> P = {1};
    for(int i = 2; i*i < M; i++){
        if(M % i == 0) {
            P.push_back(i);
            P.push_back(M/i);
        }
    }
    ll ans = 0;
    for(auto p : P){
        if(p*N <= M_) ans = max(ans, p);
    }
    cout << ans << endl;

}