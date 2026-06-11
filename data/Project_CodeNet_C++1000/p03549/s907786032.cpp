#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int t = m * 1900 + (n - m) * 100;
    int ans = t * pow(2, m);

    cout << ans << endl;

    return 0;
}