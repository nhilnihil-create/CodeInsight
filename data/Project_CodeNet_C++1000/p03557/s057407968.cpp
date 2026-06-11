#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,n) {
        cin >> b[i];
    }
    rep(i,n) {
        cin >> c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    vector<int> x,y;
    rep(i,n) {
        int point = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        x.push_back(point);
    }
    rep(i,n) {
        int point = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
        point = n - point;
        y.push_back(point);
    }
    rep(i,n) {
        ans += (ll)x[i] * y[i];
    }
    cout << ans << "\n";
    return 0;
}
