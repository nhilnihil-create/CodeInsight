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
    int n, m;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        ++mp[s];
    }
    cin >> m;
    rep(i, m) {
        string s;
        cin >> s;
        if (mp.count(s) != 0 && mp[s] > 0) {
            --mp[s];
        }
    }
    int ans = 0;
    for (auto p: mp) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}
