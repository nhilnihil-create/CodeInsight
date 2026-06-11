#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, K, ans = 1;
    cin >> N >> K;
    rep (i, N) {
        if (2 * ans < ans + K){
            ans *= 2;
        }
        else {
            ans += K;
        }
    }
    cout << ans << endl;
}