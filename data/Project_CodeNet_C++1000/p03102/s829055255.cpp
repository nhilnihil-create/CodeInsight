#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    rep(i, M) cin >> B.at(i);
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) {
        rep(j, M) {
            cin >> A.at(i).at(j);
        }
    }

    int ans = 0;
    rep(i, N) {
        int sum = 0;
        rep(j, M) {
            sum += A.at(i).at(j) * B.at(j);
        }
        sum += C;
        if (sum > 0) ans++;
    }

    cout << ans << endl;

    return 0;
}
