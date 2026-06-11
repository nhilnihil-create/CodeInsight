#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    rep(i,n) {
        int bi;
        cin >> bi;
        b[i] = bi;
    }

    int ans = 0;
    rep(i,n) {
        int sum = 0;
        for (int u=0; u<=i; u++) sum += a[u];
        for (int l=i; l<n; l++) sum += b[l];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}