#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define ll long lnog 
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, 0, s.size()) {
        mp[s[i]]++;
    }
    queue<char> que;
    rep(i, 0, 26) {
        if(mp['a'+i] == 0) {
            que.push('a'+i);
        }
    }

    string t = "";
    if(que.size() == 0 && s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
    }
    else if(que.size() != 0) {
        s += que.front();
        cout << s << endl;
    }
    else {
        string r = s;
        next_permutation(r.begin(), r.end());
        rep(i, 0, s.size()) {
           if(r[i] == s[i]) {
               t += r[i];
           }
           else {
               t += r[i];
               cout << t << endl;
               break;
           }
        }
    }
    return 0;
}