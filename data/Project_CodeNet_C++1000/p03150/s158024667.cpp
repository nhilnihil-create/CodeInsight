#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    getline(cin, s);

    string keyence="keyence";
    rep(i,7) {
        string first=keyence.substr(0,keyence.size()-i);
        string last=keyence.substr(keyence.size()-i, i);
        string::size_type fpos = s.find(first);
        string::size_type lpos = s.rfind(last);
        if (fpos != string::npos && lpos != string::npos) {
            if (i==0) {
                if (fpos==0 || fpos+7==s.size()) {
                    cout << "YES" << endl;
                    return 0;
                } else {
                    cout << "NO" << endl;
                    return 0;
                }
            } else if (fpos<lpos && fpos==0 && lpos+i==s.size()) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}