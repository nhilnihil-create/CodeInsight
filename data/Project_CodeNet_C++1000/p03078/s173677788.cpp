#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min(ll a, ll b, ll c){
    ll ret;
    ret = min(a, min(b, c));
    return ret;
}

int main(){
    int x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for(int i = 0; i < x; i++) cin >> a[i];
    for(int i = 0; i < y; i++) cin >> b[i];
    for(int i = 0; i < z; i++) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    vector<ll> ans;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int l = 0; l < z; l++){
                if((i+1)*(j+1)*(l*1) <= k) ans.push_back(a[i] + b[j] + c[l]);
                else break;
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < k; i++){
        cout << ans[i] << endl;
    }
}