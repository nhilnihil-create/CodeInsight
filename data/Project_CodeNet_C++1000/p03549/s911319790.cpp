#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    
    int ans = 1900 * m + (n - m) * 100;
    ans *= (1 << m);
    cout << ans << '\n';
    return 0;
}