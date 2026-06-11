#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int t[100010];
    int x[100010];
    int y[100010];
    string ans = "Yes";
    cin >> n;
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i=0; i<n; i++) {
        int dt = t[i+1]-t[i];
        int dist = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        if (dist > dt || dt % 2 != dist % 2) ans = "No";
        else continue;
    }
    cout << ans << endl;
    return 0;
}