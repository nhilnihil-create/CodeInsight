#include <bits/stdc++.h>
using namespace std;
int main(){
        int n, k; cin >> n >> k;
        int pos, mn = INT_MAX;
        for (int x = 1; x <= n; ++x){
            int q; cin >> q;
            if (q < mn){
                mn = q;
                pos = x;
            }
        }
        int l = pos - 1;
        int lc = ceil(l * 1.00 / (k-1));
        int r = lc * (k-1) + 1;
        r = n - r;
        int rc = ceil(r * 1.00 / (k-1));
        cout << lc + rc << endl;
    return 0;
}
