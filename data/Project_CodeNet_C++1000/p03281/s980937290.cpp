#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N; cin >> N;
    ll ans = 0;
    for(int i = 1; i <= N; i+=2){
        ll cnt = 0;
        for(int j = 1; j <= N; j++) if(i%j == 0) cnt++;
        if(cnt == 8) ans++;
    }
    cout << ans << endl;

} 
