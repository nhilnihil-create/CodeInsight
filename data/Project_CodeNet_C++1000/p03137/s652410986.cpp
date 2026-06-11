#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> x(m), d(m-1, 0);
    rep(i, 0, m) cin >> x[i];
    sort(x.begin(), x.end());

    rep(i, 0, m-1) d[i] = x[i+1] - x[i];
    sort(d.begin(), d.end());

    ll ans = 0;
    rep(i, 0, max(0LL, m-n)) ans += d[i];
    cout << ans << endl; 
    return 0; 
}