#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(ll i = a; i < b; i++)

int main(){
    ll N, K; cin >> N >> K;

    ll ans = 0;
    rep(b, K+1, N + 1){
        ll t = N / b;
        ans += (b - 1 - (K-1)) * t;
        ll t1 = N % b;
        if(t1 >= K) ans += t1 - (K - 1);
        if(K == 0) ans--;
        cerr << b << " " <<  ans << endl;
    }
    cout << ans << endl;
}
