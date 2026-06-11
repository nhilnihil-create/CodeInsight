#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string S;
    cin >> S;

    int ans = 0, l = 0, r = S.size() - 1;
    while (r - l > 0) {
        if (S[l] == S[r])
            ++l, --r;
        else {
            if (S[l] == 'x')
                ++l, ++ans;
            else if (S[r] == 'x')
                --r, ++ans;
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}