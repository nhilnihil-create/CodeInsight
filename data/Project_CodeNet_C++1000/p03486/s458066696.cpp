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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    bool ok = true;
    vector<bool> used((int)t.size(), false);
    rep(i, (int)s.size()) {
        bool flg1 = false;
        bool flg2 = false;
        rep(j, (int)t.size()) {
            if (s[i] < t[j]) {
                flg1 = true;
            }
            else if (!flg2 && s[i] == t[j] && !used[j]) {
                flg2 = true;
                used[j] = true;
            }
        }
        if (flg1) {
            cout << "Yes" << endl;
            return 0;
        }
        else if (!flg2) {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, (int)t.size()) {
        if (!used[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
