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
    vector<int> xv(n);
    vector<int> yv(n);
    vector<int> hv(n);
    rep(i, n) {
        cin >> xv[i] >> yv[i] >> hv[i];
    }
    rep(i, 101) {
        rep(j, 101) {
            int h = 0;
            rep(k, n) {
                if (hv[k] != 0) {
                    h = hv[k] + abs(xv[k] - i) + abs(yv[k] - j);
                }
            }
            bool ok = true;
            rep(k, n) {
                if (max(h - abs(xv[k] - i) - abs(yv[k] - j), 0) != hv[k]) {
                    ok = false;
                    break;
                } 
            }
            if (ok) {
                cout << i << " " << j << " " << h << endl;
                return 0;
            }
        }
    }
    return 0;
}
