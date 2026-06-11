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

    int MAX_VAL = 30;
    bool canBuy = false;
    rep(i, 30) {
        rep(j, 30) {
            if (N == 4 * i + 7 * j) canBuy = true;
        }
    }

    string ans = canBuy ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
