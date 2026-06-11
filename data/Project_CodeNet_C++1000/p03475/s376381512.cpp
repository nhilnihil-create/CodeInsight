#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<ll, ll> P;

int main(){
    ll n;
    cin >> n;
    vector<ll> c(n);
    vector<ll> s(n);
    vector<ll> f(n);
    rep(i,n-1){
        cin >> c[i] >> s[i] >> f[i];
    }

    rep(i,n-1){
        ll x = 0;
        for(ll j = i; j < n-1; j++){
            if(x < s[j]){
                x = s[j] + c[j];
            }else{
                if(x%f[j]==0){
                    x += c[j];
                }else{
                    x = (x/f[j]+1)*f[j]+c[j];
                }
            }
        }
        cout << x << endl;
    }
    cout << 0 << endl;
    return 0;
}