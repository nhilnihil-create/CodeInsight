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
    ll bc_cnt = 0;
    ll a_cnt = 0;
    ll ans = 0;
    bool flg = false;
    rep(i, n) {
        if (s[i] == 'A') ++a_cnt;
        else if (s[i] == 'B') {
            if (i+1 < n && s[i+1] == 'C') {
                ans += a_cnt;
                ++i;
            }
            else {
                a_cnt = 0;
            }
        }
        else {
            a_cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
