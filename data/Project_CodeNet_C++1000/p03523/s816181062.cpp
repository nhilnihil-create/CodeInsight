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
    string s;
    cin >> s;
    int n = s.size();
    string t = "KIHBR";
    int idx = 0;
    int flg = false;
    rep(i, n) {
        if (s[i] == t[idx]) {
            ++idx;
            flg = false;
        }
        else if (s[i] != 'A') {
            cout << "NO" << endl;
            return 0;
        }
        else if (!flg && idx != 1 && idx != 2) {
            flg = true;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (idx != 5)   cout << "NO" << endl;
    else            cout << "YES" << endl;
    return 0;
}
