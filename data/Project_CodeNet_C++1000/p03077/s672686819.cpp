#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin >> n;
    vector<ll> t(5); ll mint = LONG_LONG_MAX;
    for(int i=0; i<5; ++i){
        cin >> t[i]; mint = min(mint, t[i]);
    }
    ll res = (n+mint-1) / mint;
    res += 4;
    cout << res << endl;
    return 0;
}