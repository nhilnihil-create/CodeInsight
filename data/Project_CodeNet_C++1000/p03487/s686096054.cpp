/**
 *    author:  FromDihPout
 *    created: 2020-08-11
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    
    int cnt = 1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            cnt++;
        }
        else if (cnt != a[i-1]) {
            ans += cnt >= a[i-1] ? cnt - a[i-1] : cnt;
            cnt = 1;
        }
        else {
            cnt = 1;
        }
    }
    
    if (cnt != a[n-1]) {
        ans += cnt >= a[n-1] ? cnt - a[n-1] : cnt;
    }
    cout << ans << '\n';
    return 0;
}