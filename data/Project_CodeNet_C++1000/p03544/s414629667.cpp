#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int N;
    long long ans =1, l_1 = 1, l_2 = 2;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    rep(i, N) {
        ans = 0;
        ans = l_1 + l_2;
        l_2 = l_1; l_1 = ans;
        // cout << i+1 << "::" << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
