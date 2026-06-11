#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    vector<int> cnt(4);
    for(int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++, cnt[b]++;
    }
    sort(all(cnt));
    vector<int> ans = {1,1,2,2};
    if (cnt == ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}