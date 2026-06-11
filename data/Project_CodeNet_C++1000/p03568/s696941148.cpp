#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int a[n];
    int64_t m = 1;
    rep(i,n) {
        cin >> a[i];
        if (a[i] % 2 == 0) m *= 2; 
    }
    int64_t ans = pow(3, n) - m;
    cout << ans << endl;
}