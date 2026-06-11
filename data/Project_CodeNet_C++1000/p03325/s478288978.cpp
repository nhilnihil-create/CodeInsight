#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vi ni(n);
    rep(i, n) cin >> a[i];
    rep(i, n){
        while(a[i] % 2 == 0){
            ni[i]++;
            a[i] /= 2;
        }
    }
    ll ans = 0;
    rep(i, n){
        ans += ni[i];
    }

    cout << ans << endl;
}