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
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    int sz = n;
    vector<int> ans;
    while(1) {
        int best = -1;
        if (b.empty()) break;
        rep(i, sz) {
            if (b[i] == i + 1) best = i;
        }
        if (best == -1) {
            cout << "-1\n";
            return 0;
        }
        ans.push_back(best+1);
        b.erase(b.begin() + best);
        --sz;
    }
    reverse(ans.begin(), ans.end());
    rep(i, (int)ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}