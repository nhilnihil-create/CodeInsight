#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c, k, res = 0, ans = 0;
    cin >> a >> b >> c >> k;
    res = max(a, max(b, c));
    ans = a + b + c + (res * ((1 << k ) - 1));
    cout << ans;
}