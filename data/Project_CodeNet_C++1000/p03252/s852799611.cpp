#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void)
{
    string s, t;
    vector<int> sd(26),td(26);

    cin >> s >> t;
    //s
    rep(i, s.size()) {
        ++sd[(s[i] - 'a')];
    }
    sort(sd.begin(), sd.end());
    //t
    rep(i, t.size()) {
        ++td[(t[i] - 'a')];
    }
    sort(td.begin(), td.end());
    //sとtをチェック
    rep(i, 26) {
        if (sd[i] != td[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}