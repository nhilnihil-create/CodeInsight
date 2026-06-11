/**
 *    author:  FromDihPout
 *    created: 2020-08-10
**/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    vector<pair<pair<int,int>, int>> a(n);
    for (int i = 0; i < n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        a[i] = {{s, t}, c};
    }
    sort(all(a));
    
    vector<pair<int,int>> r(c, {-1, -1});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i].s == r[j].s && a[i].f.f >= r[j].f) {
                r[j].f = a[i].f.s;
                break;
            }
            else if (a[i].f.f - 0.5 >= r[j].f) {
                r[j].f = a[i].f.s;
                r[j].s = a[i].s;
                break;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < c; i++) {
        if (r[i].f != -1) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}