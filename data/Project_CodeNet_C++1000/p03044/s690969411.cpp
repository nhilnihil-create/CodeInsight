#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<vector<pint>> g (100005);
int n;
int seen[100005];
void search() {
    rep (i, 0, n) seen[i] = -1;
    queue<pint> q;
    q.push ({0, 0});
    seen[0] = 0;
    while (!q.empty()) {
        pint p = q.front();
        q.pop();
        int v = p.second;
        for (auto i : g[v]) {
            if (seen[i.second] == -1) {
                if (i.first % 2 == 0) {
                    // cout << i.second << "\n";
                    seen[i.second] = seen[v];
                    q.push ({seen[i.second], i.second});
                } else {
                    // cout << i.second << "\n";
                    seen[i.second] = abs (seen[v] - 1);
                    q.push ({seen[i.second], i.second});
                }
            }
        }
    }
}
int main() {
    cin >> n;
    rep (i, 0, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        g[--a].push_back ({c, --b});
        g[b].push_back ({c, a});
    }
    search();
    rep (i, 0, n) cout << seen[i] << "\n";
}