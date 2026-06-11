/**
*    created: 23.05.2020 01:27:20
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int cnt0 = 0;
    int cnt1 = 0;
    rep(i,s.size()) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }
    cout << 2 * min(cnt1, cnt0) << endl;
    return 0;
}