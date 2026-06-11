#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll N; cin >> N;
    vector<ll> V(N); for(int i = 0; i < N; i++) cin >> V[i];
    ll ans = 0;
    for(int i = 0; i < N-1; i++){
        if(V[i] == V[i+1]){
            if(i+2 < N) V[i+1] = V[i+2]+1;
            else V[i+1]++;
            ans++;
        }
        
    }
    cout << ans << endl;
}