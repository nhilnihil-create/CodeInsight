#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

ll n;
ll h[200200], a[200200], bit[200200];

ll maxi(ll i){
    ll res = 0;
    while(i>0){
        res = max(res,bit[i]);
        i -= i & -i;
    }
    return res;
}
void update(ll i, ll x){
    while(i<=n){
        bit[i] = max(bit[i],x);
        i += i & -i;
    }
}

int main(){
    cin >> n;
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> a[i];

    rep(i,n) update(h[i], a[i] + maxi(h[i]));
    cout << maxi(n) << endl;
    return 0;
}