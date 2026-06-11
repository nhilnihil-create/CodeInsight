#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {     
    int n, k;
    cin >> n >> k;
    vector<pair<long long int, long long int>> vp;
    vector<long long int> vx, vy;
    for (int i = 0; i < n; i++) {
        long long int x, y;
        cin >> x >> y;
        vx.push_back(x);
        vy.push_back(y);
        vp.emplace_back(x, y);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    long long int res = -1;
    for (int x1 = 0; x1 < n; x1++) {
        for (int x2 = x1; x2 < n; x2++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int y2 = y1; y2 < n; y2++) {
                    int c = 0;
                    for (auto p : vp) {
                        if (p.first >= vx[x1] && p.first <= vx[x2] && p.second >= vy[y1] && p.second <= vy[y2]) {
                            c++;
                        }
                    }
                    if (c >= k) {
                        long long int area = (vx[x2] - vx[x1]) * (vy[y2] - vy[y1]);
                        if (res == -1 || area < res) {
                            res = area;
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
}


