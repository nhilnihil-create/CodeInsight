#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int n;
    cin >> n;
    vector<string> blue(n);
    rep(i, n){
        cin >> blue.at(i);
    }
    int m;
    cin >> m;
    vector<string> red(m);
    rep(i, m){
        cin >> red.at(i);
    }
    int ans = 0;
    auto calc = [&](string s){
        int buf = 0;
        for (string t: blue){
            if (t == s) buf++;
        }
        for (string t: red){
            if (t == s) buf--;
        }
        return buf;
    };

    for (string t: blue){
        ans = max(ans, calc(t));
    }

    cout << ans << endl;
}
