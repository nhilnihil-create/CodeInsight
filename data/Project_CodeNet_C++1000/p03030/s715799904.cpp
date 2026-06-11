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
    vector<string> s(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> p[i];
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
        return pair{s[i], -p[i]} < pair{s[j], -p[j]};
    });
    for(int i : I) {
        cout << i + 1 << endl;
    }
    return 0;
}
