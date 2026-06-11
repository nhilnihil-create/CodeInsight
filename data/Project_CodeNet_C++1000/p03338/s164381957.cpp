#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    string s; cin >>s;
    int ret = 0;
    for (int i = 1; i < n; i++) {
        string sl = s.substr(0,i);
        string sr = s.substr(i,s.size()-i);
        int tmp = 0;
        vector<char> str;
        for (int j = 0; j < sl.size(); j++) {
            if (find(str.begin(), str.end(), sl[j])==str.end()) {
                str.push_back(sl[j]);
                if (find(sr.begin(), sr.end(), s[j])!=sr.end()) tmp++;
            }
        }
        ret = max(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}