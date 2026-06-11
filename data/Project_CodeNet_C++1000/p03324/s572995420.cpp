#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int d, n;
    cin >> d >> n;
    int ans;
    if (n == 100) {
        ans = 101 * pow(100, d);
    } else {
        ans = n * pow(100, d);
    }
    cout << ans << endl;
    return 0;
}