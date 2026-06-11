#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p+n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != n-1)
            ans += p[i];
        else
            ans += p[i]/2;
    }
    cout << ans << endl;
}