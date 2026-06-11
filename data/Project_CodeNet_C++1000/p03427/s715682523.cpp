#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;
ll ans = 0;

void dfs(string tmp) {
    if (tmp.size() >= S.size()) {
        // 計算
        // cout << tmp << endl;
        ll target = stol(tmp);
        ll input = stol(S);
        // cout << input << endl;

        ll a = 0;
        if (target <= input) {
            rep(i, tmp.size()) {
                a += tmp[i] - '0';
            }
        }
        ans = max(ans, a);
        return;
    } 

    dfs(tmp + "8");
    dfs(tmp + "9");
}

int main() {
    cin >> S;

    // N: 1 の時
    if (S.size() == 1) {
        cout << S[0] << endl;
        return 0;
    }

    ll one = S[0] - '0';
    // dfs で調べる
    for (int i = one; i >= 0; i--) {
        dfs(to_string(i));
    }

    cout << ans << endl;
}