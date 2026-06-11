#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> m(N);
    rep(i, N) cin >> m.at(i);

    int sum = 0;
    rep(i, N) {
        sum += m.at(i);
    }

    sort(m.begin(), m.end());

    int left = X - sum;
    int count = left / m.at(0);
    int ans = m.size() + count;

    cout << ans << endl;

    return 0;
}
