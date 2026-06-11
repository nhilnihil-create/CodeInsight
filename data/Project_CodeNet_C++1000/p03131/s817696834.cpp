#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    ll k, a, b; cin >> k >> a >> b;
    ll ans = 0;
    if(a + 1 >= b){
        cout << k + 1 << endl;
        return 0;
    }
    else{
        if(k <= a){
            cout << 1 + k << endl;
            return 0;
        }
        else{
            ll cnt = k - (a - 1);
            ans = a;
            bool odd = (cnt % 2 == 1 ? true : false);
            if(!odd) ans += cnt / 2 * (b - a);
            else ans += (cnt - 1) / 2 * (b - a) + 1;
            cout << ans << endl;
        }
    }
}