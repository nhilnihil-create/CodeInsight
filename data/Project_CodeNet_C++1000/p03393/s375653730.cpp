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

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    string S;
    cin >> S;
    int N = (int)S.size();

    Vi is_used(26);

    for (int i = 0; i < N; i++) {
        is_used[S[i] - 'a'] = 1;
    }

    if (N == 26) {
        string ans = S;
        bool ok = next_permutation(ans.begin(), ans.end());
        if (ok) {
            int idx = 0;
            while (idx < N && ans[idx] == S[idx]) ++idx;
            ans.erase(ans.begin() + idx + 1, ans.end());
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (is_used[i] == 0) {
                S += (char)('a' + i);
                break;
            }
        }
        cout << S << endl;
    }

    return 0;
}