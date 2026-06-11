#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    int ans = 100000;
    for(ll a = 1; a < n; a++){
        ll b = n - a;
        ll ta = a;
        int ad = 0, bd = 0;
        while(ta != 0){
            ad += ta % 10;
            ta /= 10;
        }
        while(b != 0){
            bd += b % 10;
            b /= 10;
        }
        ans = min(ans, ad + bd);
        // if(ans == 5) cout << a << endl;
    }

    cout << ans << endl;
    return 0;
}