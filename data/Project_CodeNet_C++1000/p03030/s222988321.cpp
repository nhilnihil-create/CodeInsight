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
    vector<string> S(N);
    vector<int> P(N);
    rep(i, N) cin >> S.at(i) >> P.at(i);

    vector<tuple<string, int, int>> store(N);

    rep(i, N) {
        store.at(i) = make_tuple(S.at(i), -P.at(i), i);
    }

    sort(store.begin(), store.end());

    for(auto tmp : store) {
        int ans;
        tie(ignore, ignore, ans) = tmp;
        cout << ans + 1 << endl;
    }

    return 0;
}
