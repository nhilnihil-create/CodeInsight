#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string s;
int main() {
    cin >> s;
    bool aflg = false;
    bool bflg = false;
    bool cflg = false;
    for(int i = 0; i < 3; ++i) {
        if(s.at(i) == 'a') aflg = true;
        if(s.at(i) == 'b') bflg = true;
        if(s.at(i) == 'c') cflg = true;
    }

    if(aflg && bflg && cflg) cout << "Yes" << endl;
    else cout << "No" << endl;
}