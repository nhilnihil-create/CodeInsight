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
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    rep(i, m) {
        int tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        ab[i] = make_pair(tmp_b, tmp_a);
    }
    sort(ab.begin(), ab.end());
    int ans = 0;
    int now = 0;
    rep(i, m) {
        if (now <= ab[i].second) {
            ++ans;
            now = ab[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
