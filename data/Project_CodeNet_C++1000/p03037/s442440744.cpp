#include <iostream>
using namespace std;
 
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int l[m], r[m];
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }
    int lmax = l[0], rmin = r[0];
    for (int i = 1; i < m; i++) {
        if (lmax < l[i]) lmax = l[i];
        if (rmin > r[i]) rmin = r[i];
    }

    int res = rmin - lmax + 1;
    if (res > 0) cout << res << endl;
    else cout << 0 << endl;
}