#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;
//const static CELL  = -1;
 
ll digsum(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
 
int main(){
    ll N, N_; cin >> N; N_ = N;
    ll N_SUM = digsum(N);
    ll dig = 0;
    while(N_ != 0) {
        dig++;
        N_ /= 10;
    }
    ll d = N / pow(10, dig-1);
    ll ans = 9*(dig-1);
    ans += d-1;
    cout << max(ans, N_SUM) << endl;
 
 
 
}