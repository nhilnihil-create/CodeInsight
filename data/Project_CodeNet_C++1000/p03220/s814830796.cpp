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
    double T, A;
    cin >> N >> T >> A;
    vector<int> H(N);
    rep(i, N) cin >> H.at(i);

    double minDiff = 1000000;
    int ans = 0;
    rep(i, N) {
        double temp = T - H.at(i) * 0.006;
        double diff = abs(temp - A);
        if (minDiff > diff) {
            minDiff = diff;
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
