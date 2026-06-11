#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep (i, n) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            ans++;
        }
    }
    
    cout << ans << endl;


    return 0;
}