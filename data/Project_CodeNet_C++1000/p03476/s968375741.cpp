#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N = 1e5+2;
    vector<bool> B(N, true); B[0] = B[1] = false;
    for(int i = 2; i*i <= N; i++){
        ll p = i;
        ll cnt = 2;
        while(p*cnt < N){
            B[p*cnt] = false;
            cnt++;
        }
    }
    vector<ll> D(N);
    for(int i = 2; i < N; i++){
        if(B[i]){
            if(B[(i+1)/2]) D[i]++;
        }
    }
    for(int i = 0; i < N-1; i++) D[i+1] += D[i];

    ll Q; cin >> Q;
    while(Q--){
        ll l, r; cin >> l >> r;
        cout << D[r] - D[l-1] << endl;

    }

}
