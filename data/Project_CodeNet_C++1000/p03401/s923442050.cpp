#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    vec d;
    d.push_back(abs(a[0]));
    rep(i, n-1) d.push_back(abs(a[i] - a[i+1]));
    d.push_back(abs(a[n-1]));

    lint s = accumulate(all(d), 0LL);

    rep(i, n) {
        lint o = s;
        o -= d[i];
        o -= d[i+1];
        if (i == 0) {
            o += abs(a[1]);
        }
        else if (i == n-1) {
            o += abs(a[n-2]);
        }
        else {
            o += abs(a[i-1] - a[i+1]);
        }
        cout << o << endl;
    }
    return 0;
}