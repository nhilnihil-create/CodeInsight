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
    vector<int> t(n+1, 0);
    vector<int> x(n+1, 0);
    vector<int> y(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> t[i] >> x[i] >> y[i];
    rep(i, n) {
        int dt = t[i+1] - t[i];
        int dx = x[i+1] - x[i];
        int dy = y[i+1] - y[i];
        int diff = dt - abs(dx) - abs(dy);
        if (diff < 0 || diff % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
