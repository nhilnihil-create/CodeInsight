#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k,a,b;
    cin >> k >> a >> b;
    if (b-a <= 2){
        cout << k+1 << endl;
    }
    else{
        if (k <= a-1){
            cout << k+1 << endl;
        }
        else{
            ll x = (k+1-a)/2;
            ll ans = (b-a)*x +a;
            if ((k+1-a)%2 == 1){
                ans++;
            }
            cout << ans << endl;
        }

    }
}