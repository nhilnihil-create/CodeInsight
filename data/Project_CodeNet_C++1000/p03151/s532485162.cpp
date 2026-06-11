#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    ll n; cin >> n;
    ll sumA = 0, sumB = 0;
    ll d;
    ll ans = 0;
    vector<ll> a(n),b(n),c;
    rep(i,n) {
        cin >> a[i];
        sumA += a[i];
    }
    rep(i,n) {
        cin >> b[i];
        sumB += b[i];
    }

    if(sumA < sumB){
        cout << -1;
        return 0;
    }else{
        rep(i,n){
            if(a[i] >= b[i]){
                c.push_back(a[i]-b[i]);
            }
        }
    }
    d = sumA-sumB;
    sort(c.begin(),c.end());
    ans = n;
    rep(i,c.size()){
        if(d - c[i] >= 0){
            ans --;
            d -= c[i];
        }
    }
    cout << ans;

    return 0;
}
