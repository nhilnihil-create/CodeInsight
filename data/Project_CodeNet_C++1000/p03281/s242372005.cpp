#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)

int main() {
    int n, cnt = 0, ans = 0;
    cin >> n;
    rep2(i, n) {
        rep2(j, i) {
            if (i % j == 0)
                cnt++;
        }
        if (cnt == 8 && i % 2 == 1) {
            ans++;
        }
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}