#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
    string s;
    int flg,cnt1, cnt2, ans;

    cin >> s;

    cnt1 = 0;
    flg = 0;
    rep(i, s.size()) {
        if (flg != s[i]-'0')
            ++cnt1;
        if (++flg == 2)
            flg = 0;
    }
    cnt2 = 0;
    flg = 1;
    rep(i, s.size()) {
        if (flg != s[i]-'0')
            ++cnt2;
        if (++flg == 2)
            flg = 0;
    }
    ans = min(cnt1, cnt2);
    cout << ans << endl;

    return 0;
}
