#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<ll, ll> P;

int main(){
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);
    vector<ll> b(n);
    ll max_a = 0;
    ll idx = 0;

    rep(i,n){
        cin >> a[i] >> b[i];
        if(max_a < a[i]){
            max_a = a[i];
            idx = i;
        }
    }

    sort(b.begin(), b.end(), greater<ll>());
    ll ans = 0;
    rep(i,n){
        if(b[i] > max_a){
            h -= b[i];
            ans ++;
            if(h <= 0){
                cout << ans << endl;
                return 0;
            }
        }
    }

    if(h%max_a==0){
        cout << ans+h/max_a << endl;
    }else{
        cout << ans+h/max_a+1 << endl;
    }
    return 0;
}