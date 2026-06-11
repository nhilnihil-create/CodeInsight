#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll gezan_fix = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        gezan_fix += max(0, b[i] - a[i]);
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
        return b[i] > b[j];
    });
    ll ans = 0;
    for(int i : I) {
        if(a[i] < b[i]) {
            ans += b[i];
        } else if(a[i] - b[i] < gezan_fix) {
            gezan_fix -= (a[i] - b[i]);
            ans += b[i];
        }
    }
    cout << ans << endl;
    return 0;
}
