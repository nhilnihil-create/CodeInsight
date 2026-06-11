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
bool is_perfect_square(ll n) {
    return ll(sqrt(n)) * ll(sqrt(n)) == n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        ll rt_ab = ll(sqrt(a * b));
        if(is_perfect_square(a * b)) {
            cout << 2 * rt_ab - 2 - (a != b) << endl;
        } else {
            cout << 2 * rt_ab - ((a * b - 1) / rt_ab == rt_ab) - 1 << endl;
        }
    }
    return 0;
}
