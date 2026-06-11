#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    rep(i,s.size()) {
        if (s==t) {
            cout << "Yes" << endl;
            return 0;
        } else {
            char lastchar=t.at(t.size()-1);
            t.pop_back();
            t = lastchar + t;
        }
    }

    cout << "No" << endl;
    return 0;
}