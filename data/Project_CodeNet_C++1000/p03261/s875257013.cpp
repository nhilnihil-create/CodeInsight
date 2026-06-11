#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<string> W(N);
    rep(i, N) cin >> W.at(i);

    bool isOk1 = true;
    rep(i, N - 1) {
        if (W.at(i).at(W.at(i).size() - 1) != W.at(i + 1).at(0)) isOk1 = false;
    }

    bool isOk2 = true;
    map<string, int> table;
    rep(i, N) { // 初期化
        table[(W.at(i))] = 0;
    }
    rep(i, N) {
        table.at(W.at(i))++;
        if (table.at(W.at(i)) > 1) isOk2 = false;
    }

    string ans = (isOk1 && isOk2) ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
