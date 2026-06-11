#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    int ans = 1;
    rep(i, N) {
        int number = (i + 1) * (i + 1);
        if (number > N) {
            ans = i * i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}