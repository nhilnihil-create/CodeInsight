#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define rep11(i, n) for(int i = 1; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
typedef struct { int x; int y; } Pos;
using namespace std;

string s, s_, t;
int check() {
    int ret = -1;
    bool match;
    rep01(i, (int)s_.length() - t.length()) {
        if (s_[i] == t[0] || s_[i] == '?') {
            match = true;
            rep(j, (int)t.length()) {
                if (s_[i + j] != '?' && s_[i + j] != t[j]) match = false;
            }
            if (match) ret = i;
        }
    }
    return ret;
}
int main() {
    cin >> s_ >> t;
    int b = check();
    if (0 <= b) {
        s = s_;
        rep(i, (int)t.length())
            s[i+b] = t[i];
        rep(i, (int)s.length())
            if (s[i] == '?') s[i] = 'a';
        cout << s << endl;
    }
    else {
        cout << "UNRESTORABLE" << endl;
    }

    return 0;
}