#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll N,M;
    cin >> N >> M;
    if(N>M) swap(N, M);
    if(N==1 && M==1){
        cout << 1 << endl;
    } else if(N==1&& M>=2){
        cout << M-2 << endl;
    } else if(N==2){
        cout << 0 << endl;
    } else {
        ll ans = (N-2)*(M-2);
        cout << ans << endl;
    }
}