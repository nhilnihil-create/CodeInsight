#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a, b;
    vector<int> G[n];
    int outdeg[2][n];
    fill(outdeg[0], outdeg[2], 0);
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        outdeg[s[a] - 'A'][b]++;
        if (a == b) continue;
        G[b].emplace_back(a);
        outdeg[s[b] - 'A'][a]++;
    }
    set<int> S;
    bool deleted[n] = {};
    int sum = n;
    rep(i, n) {
        int mn = min(outdeg[0][i], outdeg[1][i]);
        if (mn == 0){
            S.emplace(i);
            deleted[i] = true;
            sum--;
        }
    }
    while(!S.empty()){
        int v = *S.begin();
        S.erase(S.begin());
        for(int from : G[v]){
            if (deleted[from]) continue;
            outdeg[s[v] - 'A'][from]--;
            if (outdeg[s[v] - 'A'][from] == 0) {
                S.emplace(from);
                deleted[from] = true;
                sum--;
            }
        }
    }
    cout << (sum > 0 ? "Yes" : "No") << endl;
    return 0;
}