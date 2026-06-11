#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
ll lcm(ll a, ll b){
    ll ret = (a * b)/gcd(a,b);
    return ret;
}

int main(){
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N), d(N);
    rep(i, 0, N) cin >> x[i];
    x.push_back(X);
    sort(x.begin(), x.end());
    rep(i, 0, N) d[i] = x[i+1] - x[i];
    ll ans = d[0];
    rep(i, 1, N) ans = gcd(ans, d[i]);
    cout << ans << endl;
    return 0;
}