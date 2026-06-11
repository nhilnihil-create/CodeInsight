#include <bits/stdc++.h>
using namespace std;


int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, t;
    cin >> a >> b >> t;
    int ans = t / a * b;
    cout << ans << '\n';
    return 0;
}
