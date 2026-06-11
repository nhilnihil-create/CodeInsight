#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    if (s.at(0)!='A') {
        cout << "WA" << endl;
        return 0;
    }

    string sbuff=s.substr(2, s.size()-3);
    int pos;
    if (sbuff.find("C")==string::npos) {
        cout << "WA" << endl;
        return 0;
    } else {
        pos=s.find("C");
    }

    for (int i=1; i<(int)s.size(); ++i) {
        if (i==pos) continue;
        if (isupper(s.at(i))) {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;
    return 0;
}