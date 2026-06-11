/**
 *    author:  FromDihPout
 *    created: 2020-08-09
**/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const long long INF = 6e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    
    long long area = INF;
    for (int p1 = 0; p1 < n; p1++) {
        for (int p2 = 0; p2 < n; p2++) {
            for (int p3 = 0; p3 < n; p3++) {
                for (int p4 = 0; p4 < n; p4++) {
                    long long x1 = min({a[p1].f, a[p2].f, a[p3].f, a[p4].f});
                    long long x2 = max({a[p1].f, a[p2].f, a[p3].f, a[p4].f});
                    long long y1 = min({a[p1].s, a[p2].s, a[p3].s, a[p4].s});
                    long long y2 = max({a[p1].s, a[p2].s, a[p3].s, a[p4].s});
                    
                    int cnt = 0;
                    for (int i = 0; i < n; i++) {
                        if (a[i].f >= x1 && a[i].f <= x2
                            && a[i].s >= y1 && a[i].s <= y2) {
                            cnt++;
                        }
                        if (cnt >= k) break;
                    }
                    if (cnt >= k) {
                        area = min(area, (x2 - x1) * (y2 - y1));
                    }
                }
            }
        }
    }
    
    cout << area << '\n';
    return 0;
}