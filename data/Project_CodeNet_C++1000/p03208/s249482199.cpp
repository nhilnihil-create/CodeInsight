#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    sort(h.begin(), h.end());//10 11 12 14 15
    ll ans = 10101010000000;
    rep(i, n-k+1){
        ans = min(ans, h[i+k-1]-h[i]);
    }
    cout << ans << endl;
}