#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]-=(i+1);
    sort(a.begin(), a.end(), greater<int>());
    int b;
    b = a[n/2];
    ll ans = 0;
    rep(i, n) {
        ans += abs(a[i]-b);
    }
    cout << ans;
}
