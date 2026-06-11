#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N; cin >> N;
    ll ans = 0;
    for (int i = 1; i < 1e6+1; i++){
        ll n = N - i;
        if(n%i == 0){
            ll x = n / i;
            if(x > i){
                ans += x;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}