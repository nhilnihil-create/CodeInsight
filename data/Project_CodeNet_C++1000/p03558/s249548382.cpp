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


int main() {
    int K;
    cin >> K;
    deque<pii> D;
    D.push_front({1, 1});
    int now = 1;
    const int INF = 1 << 29;
    vector<int> ans(K, INF);
    while(!D.empty()) {
        pii p = D.back(); D.pop_back();
        if (ans[p.second] == INF) ans[p.second] = p.first; else continue;
        now = p.first;

        D.push_back({now, p.second * 10 % K});
        D.push_front({now + 1, (p.second + 1) % K});
    }
    cout << ans[0] << endl;
    return 0;
}
