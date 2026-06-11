#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s, t;
    cin >> s >> t;
    bool okflag = false;

    for(int i = 0; i < s.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (j + i >= s.size()) {
                if (s[j+i-s.size()] != t[j]) break;
            } else {
                if (s[j+i] != t[j]) break;
            }
            cnt++;
            if (cnt == s.size()) okflag = true;
        }
        if (okflag) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}