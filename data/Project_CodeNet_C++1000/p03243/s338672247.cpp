#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

bool isSameDigits(int x) {
    int left = x % 10;
    bool isSame = true;
    while (x > 0) {
        if (left != x % 10) isSame = false;
        x /= 10;
    }
    return isSame;
}

int main() {
    int N;
    cin >> N;

    int ans;
    for (int i = N; i <= 999; i++) {
        if (isSameDigits(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
