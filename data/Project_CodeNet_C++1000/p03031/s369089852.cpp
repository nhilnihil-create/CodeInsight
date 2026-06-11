#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 58;
const int INT_INF = 1 << 28;
const double PI = acos(-1.0);

int main() {
    int n, m;
    cin >> n >> m;
    vvi s(m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int t;
            cin >> t;
            s[i].push_back(t);
        }
    }
    vi p(m);
    rep(i, m) cin >> p[i];
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool flag = true;
        rep(i, m) {
            int sum = 0;
            rep(j, s[i].size()) {
                if (bit & (1 << (s[i][j] - 1))) sum++;
            }
            if (sum % 2 != p[i]) flag = false;
        }
        if (flag) ans++;
    }
    cout << ans << endl;
}