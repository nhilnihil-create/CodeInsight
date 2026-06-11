/**
 *    author:  FromDihPout
 *    created: 2020-08-20
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n+1; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int ans = a[1] - a[0];
    for (int i = 2; i < n+1; i++) {
        ans = __gcd(ans, a[i] - a[i-1]);
    }
    cout << ans << '\n';
    return 0;
}