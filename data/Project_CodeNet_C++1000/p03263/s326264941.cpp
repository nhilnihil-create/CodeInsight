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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<tuple<int, int, int, int>> ans;
    rep(i, h) {
        rep(j, w) {
            if (i == h-1 && j == w-1) break;
            if (i % 2 == 0) {
                if (a[i][j] % 2 == 1) {
                    if (j == w-1) {
                        ++a[i+1][j];
                        --a[i][j];
                        ans.emplace_back(i, j, i+1, j);
                    }
                    else {
                        ++a[i][j+1];
                        --a[i][j];
                        ans.emplace_back(i, j, i, j+1);
                    }
                }
            }
            else {
                if (a[i][w-1-j] % 2 == 1) {
                    if (j == w-1) {
                        ++a[i+1][w-1-j];
                        --a[i][w-1-j];
                        ans.emplace_back(i, w-1-j, i+1, w-1-j);
                    }
                    else {
                        ++a[i][w-1-j-1];
                        --a[i][w-1-j];
                        ans.emplace_back(i, w-1-j, i, w-1-j-1);
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto ap: ans) {
        cout << get<0>(ap) + 1 << " " << get<1>(ap) + 1 << " " << get<2>(ap) + 1 << " " << get<3>(ap) + 1 << endl; 
    } 
    return 0;
}