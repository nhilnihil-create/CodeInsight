#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

using Graph = vector<Vi>;
Graph g;
int N;
Vi C, ans;

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    cin >> N;
    g.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    C.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end(), greater<int>());


    int start = 0;
    for (int i = 0; i < N; i++) {
        if (g[i].size() > g[start].size()) {
            start = i;
        }
    }

    ans.resize(N);
    int now = 0;
    queue<Pii> q;
    q.emplace(start, -1);
    while (!q.empty()) {
        int idx, par;
        tie(idx, par) = q.front();
        q.pop();
        ans[idx] = C[now++];
        for (const auto& to : g[idx]) {
            if (to == par) continue;
            q.emplace(to, idx);
        }
    }

    ll score = 0;
    for (int i = 1; i < N; i++) {
        score += C[i];
    }

    cout << score << '\n';

    for (int i = 0; i < N - 1; i++) {
        cout << ans[i] << ' ';
    }
    cout << ans[N - 1] << endl;

    return 0;
}