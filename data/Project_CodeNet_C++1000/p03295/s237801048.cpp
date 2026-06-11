/**
 *    author:  FromDihPout
 *    created: 2020-08-18
**/

#include <bits/stdc++.h>
using namespace std;


const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end());
    
    int ans = 1;
    int l = -INF, r = INF;
    for (int i = 0; i < m; i++) {
        int x = a[i].first, y = a[i].second;
        if (x >= r) {
            l = x;
            r = y;
            ans++;
        }
        else {
            l = max(l, x);
            r = min(r, y);
        }
    }
    cout << ans << '\n';
}