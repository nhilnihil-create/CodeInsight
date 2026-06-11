#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    ll ans = 0;
    rep(i,n){
        ll cnt1 = n - (upper_bound(ALL(c),b[i]) - c.begin());
        ll cnt2 = lower_bound(ALL(a), b[i]) - a.begin();
        ans += cnt1 * cnt2;
    }
    cout << ans << endl;
}