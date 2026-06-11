#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, k;
    cin >> n >> k;
    
    ll zero = 0, half = 0;
    rep(i, 1, n+1){
        if(i%k == 0) zero++;
        if(k%2 == 0 && i%k == (ll)(k/2)) half++;
    }

    ll ans = pow(zero, 3) + pow(half, 3);
    cout << ans << endl;
    return 0;
}