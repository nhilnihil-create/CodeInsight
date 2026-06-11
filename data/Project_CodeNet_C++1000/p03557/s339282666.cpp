#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
//a[?] < b[?] < c[?]
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0;
    rep(i,n){
        ll A = (lower_bound(all(a), b[i]))-a.begin();
        ll C =  n-((upper_bound(all(c), b[i]))-c.begin());
        ans += A*C;
    }
    cout << ans << endl;
    return 0;
}