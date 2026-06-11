#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n = 5;
    vector<ll> a(n, 0), b(n, 0), c(n, 0);
    rep1(i, n){
        cin >> c[i];
        if (c[i]%10==0) a[i] = c[i];
        else a[i] = (c[i]/10+1)*10;
        b[i] = c[i]%10;
    }
    ll ndx = 0, mini = 200;
    rep1(i, n){
        if (b[i]==0) continue;
        if (mini > b[i]){
            ndx = i;
            mini = b[i];
        }
    }
    ll ans = 0;
    rep1(i, n){
        if (i == ndx) continue;
        ans += a[i];
    }
    ans += c[ndx];
    cout << ans << endl;
}