#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> asum(n+1);
    rep(i, n) {
        cin >> a[i];
        if ( i == 0 ) asum[0] = abs(a[i]);
        else          asum[i] = asum[i-1] + abs(a[i] - a[i-1]);
    }
    asum[n] = asum[n-1] + abs(0 - a[n-1]);
    rep(i, n) {
        int tmp_num = 0;
        if ( i == 0 ) {
            tmp_num = abs(a[1] - 0);
            cout << ( asum[n] - asum[i+1] ) + tmp_num << endl;
        }
        else if ( i == n - 1 ) {
            tmp_num = abs(0 - a[n-2]);
            cout << tmp_num + asum[i-1] << endl;
        }
        else {
            tmp_num = abs(a[i+1] - a[i-1]);
            cout << ( asum[n] - asum[i+1] ) + tmp_num + asum[i-1] << endl;
        }
    }
    return 0;
}
