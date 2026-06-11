#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a.at(i);
    rep(i, n) cin >> b.at(i);
    rep(i, n) cin >> c.at(i);

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    rep(i, n){
        int k = b.at(i);
        auto low_pos = lower_bound(a.begin(), a.end(), k);
        ll low_idx = distance(a.begin(), low_pos);
        ll num_A = (low_pos == a.end()) ? n : low_idx;

        auto upper_pos = upper_bound(c.begin(), c.end(), k);
        ll upper_idx = distance(c.begin(), upper_pos);
        ll num_C = (upper_pos == c.end()) ? 0 : n - upper_idx;

        ans += num_A * num_C;
    }

    cout << ans << endl;
}