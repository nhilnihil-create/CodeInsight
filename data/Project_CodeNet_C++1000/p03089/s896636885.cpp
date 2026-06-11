#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

vector<int> ans(0);
bool dfs(vector<int> cur) {
    // dump(cur);
    if (cur.size() == 0) { return true; }

    for (int i = cur.size() - 1; 0 <= i; i--) {
        if (cur[i] == i) {
            vector<int> nxt(0);
            for (int j = 0; j < cur.size(); j++) {
                if (i != j) { nxt.push_back(cur[j]); }
            }
            if (dfs(nxt)) {
                ans.push_back(i);
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> prev(N, 0);
    rep(i, N) {
        cin >> prev[i];
        prev[i]--;
    }

    vector<int> ans(0);
    while (prev.size() > 0) {
        dump(prev);

        int pos = -1;
        for (int i = 0; i < prev.size(); i++) {
            if (prev[i] == i) pos = i;
        }

        if (pos == -1) {
            cout << -1 << endl;
            return 0;
        }

        ans.push_back(pos);

        vector<int> nxt(0);
        for (int i = 0; i < prev.size(); i++) {
            if (i != pos) { nxt.push_back(prev[i]); }
        }
        prev = nxt;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[ans.size() - i - 1] + 1 << endl;
    }

    return 0;
}