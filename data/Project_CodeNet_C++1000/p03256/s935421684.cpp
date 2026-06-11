#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

bool hasLoop(vector<vector<int>> &G) {
    int N = G.size();
    vector<int> cnt(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < G[i].size(); j++) {
            cnt[G[i][j]]++;
        }
    }
    vector<int> S;
    for (int i = 0; i < N; i++) {
        if (!cnt[i]) S.push_back(i);
    }
    if (!S.size()) return true;

    vector<int> L;
    while(!S.empty()) {
        int n = S.back(); S.pop_back();
        L.push_back(n);
        for(int i = 0; i < G[n].size(); i++) {
            cnt[G[n][i]]--;
            if (!cnt[G[n][i]]) {
                S.push_back(G[n][i]);
            }
        }
    }
    return L.size() != N;
}

void solve() {
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;

    vector<vector<int>> G(4 * N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (s[a] == 'A' && s[b] == 'A') {
            G[a * 4].push_back(b * 4 + 1);
            G[b * 4].push_back(a * 4 + 1);
        } else if (s[a] == 'B' && s[b] == 'B') {
            G[a * 4 + 2].push_back(b * 4 + 3);
            G[b * 4 + 2].push_back(a * 4 + 3);
        } else if (s[a] == 'A' && s[b] == 'B') {
            G[a * 4 + 1].push_back(b * 4 + 2);
            G[b * 4 + 3].push_back(a * 4);
        } else {
            G[a * 4 + 3].push_back(b * 4);
            G[b * 4 + 1].push_back(a * 4 + 2);
        }
    }
    if (hasLoop(G)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}