#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >>s;
    int w=0;
    for (auto c: s) if(c=='W'){w++;}

    int left_white = 0, t;
    long long ret = 0;
    for (int i = 0; i < w; i++) {
        t = s.substr(left_white, s.size()).find('W');
        if (t==0) {
            // do nothing
        }
        else {
            // s[left_white] = 'W';
            if (t>0) s[left_white+t] = 'B';
            ret += t;
        }
        left_white++;
    }
    cout << ret << endl;
    return 0;
}