#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }




int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int now = 0;
    int sum = 0;
    rep(i, n) {
        sum += abs(now - a[i]);
        now = a[i];
    }
    sum += abs(a[a.size()-1]);

    rep(i, n) {
        int ans = sum;
        if(i == n-1) {
            int prev = a[i-1];
            ans -= abs(prev-a[i]);
            ans -= abs(a[i]);
            ans += abs(a[i-1]);
        } else {
            int prev = 0;
            if(i > 0) prev = a[i-1];
            ans -= abs(prev-a[i]);
            ans -= abs(a[i]-a[i+1]);
            ans += abs(prev-a[i+1]);
        }
        cout << ans << endl;
    }

    return 0;
}
