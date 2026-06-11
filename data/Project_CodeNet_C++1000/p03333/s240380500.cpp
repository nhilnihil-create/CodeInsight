#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n; cin >> n;

    vector<ll> left(n), right(n);
    rep(i,n) cin >> left[i] >> right[i];
    sort(left.begin(),left.end(),greater<ll>());
    sort(right.begin(),right.end());

    ll ans = 0, count = 0;
    rep(i,n) {
        count += left[i]; ans = max(ans, count);
        count -= right[i]; ans = max(ans, count);
    }

    count = 0;
    rep(i,n) {
        count -= right[i]; ans = max(ans, count);
        count += left[i]; ans = max(ans, count);
    }
    
    cout << ans * 2 << endl;
    return 0;
}