#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    int pt = 0, px = 0, py = 0;
    bool flag = true;
    rep(i, N) {
        int t, x, y; cin >> t >> x >> y;
        int d = abs(x-px)+abs(y-py);
        if (d>t-pt) flag = false;
        if (d%2!=(t-pt)%2) flag = false;
        pt = t, px = x, py = y;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}