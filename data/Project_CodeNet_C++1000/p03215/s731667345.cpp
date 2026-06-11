#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t




int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N+1); for(int i = 1; i < N+1; i++) cin >> A[i];
    for(int i = 0; i < N; i++) A[i+1] = A[i]+A[i+1];
    vector<bitset<41>> B;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N+1; j++){
            ll temp = A[j]-A[i];
            bitset<41> b = temp;
            B.push_back(b);
        }
    }
    ll ans = 0;
    for(int i = 41; i >= 0; i--){
        ll c = 0;
        vector<bitset<41>> B_;
        for(auto b : B){
            if(b[i] == 1) {
                c++;
                B_.push_back(b);
            }
        }
        if(c >= K) {
            ans += pow(2, i);
            B = B_;
        }


    }
    cout << ans << endl;
}