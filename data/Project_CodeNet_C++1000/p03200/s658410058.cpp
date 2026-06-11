#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    long long bc = 0, bp = 0; for (int i = 0; i < s.size(); i++) if(s[i]=='B'){bc++;bp+=i;}
    cout << (s.size()-1 + s.size()-bc) * bc / 2 - bp << endl;
    /**
    bool debug = true;
    string s; cin >>s;
    int w=0;
    for (auto c: s) if(c=='W'){w++;}
    if (debug) cout << s << endl << "----" << endl;

    int left_white = 0, ret = 0, t;
    for (int i = 0; i < w; i++) {
        t = s.substr(left_white, s.size()).find('W');
        if (t==0) {
            // do nothing
        }
        else {
            s[left_white] = 'W';
            if (t>0) s[left_white+t] = 'B';
            ret += t;
        }
        if (debug) cout << s << " " << t << endl;
        left_white++;
    }
    if (debug) cout << "----" << endl << s << endl;
    */
    return 0;
}