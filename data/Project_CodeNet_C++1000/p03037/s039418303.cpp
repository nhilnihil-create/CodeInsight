#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;

    int l,r;
    int l_max = 0;
    int r_min = n-1;
    rep(i,m) {
        cin >> l >> r;
        l--;
        r--;
        l_max = max(l, l_max);
        r_min = min(r, r_min);
    }

    cout << max(r_min-l_max+1, 0) << endl;
    return 0;
}