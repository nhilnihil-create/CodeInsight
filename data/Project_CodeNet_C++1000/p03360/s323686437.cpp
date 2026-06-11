#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ans = a + b + c + max(a, max(b, c)) * (pow(2, k) - 1);

    cout << ans << endl;
}