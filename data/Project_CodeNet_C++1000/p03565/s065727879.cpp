#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int idx = -1;
    rep(i, n - m + 1) {
        bool flg = true;
        for (int j = i; j < i + m; ++j) {
            if (s[j] != '?' && s[j] != t[j-i]) {
                flg = false;
            }  
        }
        if (flg) {
            idx = i;
        }
    }
    //cout << idx << endl;
    if (idx < 0) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i, m) {
        s[idx+i] = t[i];
    }
    rep(i, n) {
        if (s[i] == '?') {
            cout << 'a';
        }
        else {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
