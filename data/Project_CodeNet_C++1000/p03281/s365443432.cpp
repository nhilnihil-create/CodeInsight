/**
*    created: 26.06.2020 17:15:30
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 0;
    rep2(i,1,n+1) {
        int cnt = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) cnt += 2;
            if (j * j == i) cnt--;
        }
        if (i % 2 == 1 && cnt == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}