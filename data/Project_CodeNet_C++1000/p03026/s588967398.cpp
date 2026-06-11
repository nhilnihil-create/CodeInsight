#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>());
    vector<int> c(N);
    int s;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        s = a;
    }

    rep(i, N) { cin >> c[i]; }

    sort(all(c), greater<int>());

    ll ans = accumulate(all(c), 0LL) - c[0];
    queue<int> que;
    map<int, int> ma;
    int cur = 0;
    ma[s + 1] = c[cur];
    que.push(s);
    while (!que.empty()) {
        int t = que.front();
        que.pop();

        for (auto n : G[t]) {
            if (ma[n + 1] != 0)
                continue;
            cur++;
            ma[n + 1] = c[cur];
            que.push(n);
        }
    }

    cout << ans << endl;
    for (auto m : ma) {
        cout << m.second << " ";
    }
    cout << endl;
}