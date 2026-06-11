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
const int N = 1'000, W = N * 10'000;
int w[N], s[N], v[N];
ll opt[W+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> s[i] >> v[i];
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) { return s[i] + w[i] > s[j] + w[j]; });
    for(int i : I) {
        for(int ww = 0; ww <= s[i]; ww++) {
            opt[ww] = max(opt[ww], opt[min(ww + w[i], W)] + v[i]);
        }
    }
    cout << opt[0] << endl;
    return 0;
}