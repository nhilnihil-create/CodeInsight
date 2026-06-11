#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string s;
    cin >> s;
    for (int bit = 0; bit < (1 << 3); bit++){
        int tmp = s.at(0) - '0';
        string ans = "";
        ans += s.at(0);
        rep(i, 3){
        if (bit & (1 << i)){
            tmp += s.at(i + 1) - '0';
            ans += '+';
            ans += s.at(i + 1);
        }
        else{
            tmp -= s.at(i + 1) - '0';
            ans += '-';
            ans += s.at(i + 1);
        }
        }
        if (tmp == 7) {
            cout << ans << "=7" << endl;
            return 0;
    }
    }
}
