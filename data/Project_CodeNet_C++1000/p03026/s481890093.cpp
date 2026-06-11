#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<int> c(N, 0), ans(N, -1);
    vector<P> t(N);

    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        c[a]++;
        c[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, N) {
        t[i] = P(c[i], i);
    }
    sort(all(t));

    rep(i, N) cin >> c[i];
    sort(all(c));

    queue<int> que;
    que.push(t[N - 1].second);
    int cost = N - 1;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        ans[v] = c[cost];
        cost--;
        rep(i, G[v].size()) {
            int to = G[v][i];
            if (ans[to] != -1) continue;
            que.push(to);
        }
    }
/*
    rep(i, N) {
        cout << t[i].second << "  " << t[i].first << endl;
    //    ans[t[i].second] = c[i];
    }
*/
    ll res = 0;
    rep(i, N - 1) res += c[i];

    cout << res << endl;
    rep(i, N - 1) cout << ans[i] << " ";
    cout << ans[N - 1] << endl;
    return 0;
}