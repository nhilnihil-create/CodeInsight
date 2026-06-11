#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;



 
int main(){
    ll N, K; cin >> N >> K;
    bitset<40> k(K+1);
    vector<bitset<40>> A(N);
    for(ll i = 0; i < N; i++) {
        ll x; cin >> x;
        bitset<40> temp(x);
        A[i] = temp;
    }
    vector<int> Set(40);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 40; j++){
            if(A[i][j] == 1) Set[j]++;
        }
    }

    ll Max = 0;

    for(ll i = 39; i >= 0; i--){
        bitset<40> tempK = k;
        if(tempK[i] == 0) continue;
        tempK.reset(i);
        if(tempK.to_ullong() > K) continue;
        for(ll j = i-1; j >= 0; j--){
            if(Set[j] > N - Set[j]) tempK.reset(j);
            else tempK.set(j);
        }
        if(tempK.to_ullong() > K) continue;
        ll ans = 0;
        for(ll j = 0; j < N; j++){
            ans += (tempK ^ A[j]).to_ullong();
        }
        Max = max(ans, Max);
    }
    cout << Max << endl;
}
