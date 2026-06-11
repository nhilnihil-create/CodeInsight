#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (int &i: p) cin >> i;
    sort(p.begin(), p.end());
    int ans = 0;
    for (int i=0; i<n-1; ++i) {
        ans += p[i];
    }
    ans += p[n-1] / 2;
    cout << ans << endl;
}