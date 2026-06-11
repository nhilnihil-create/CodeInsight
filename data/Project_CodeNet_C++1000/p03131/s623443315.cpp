#include <bits/stdc++.h>

using namespace std;


int main() {
    long long k, a, b;
    cin >> k >> a >> b;
    if(b - a <= 2 || k <= a) {
        cout << k + 1 << "\n";
        return 0;
    } 
    long long ans = a, t = k - a + 1;
    if(t % 2 == 1) {
        ans++;
    }
    cout << ans + t / 2 * (b - a) << "\n";
    return 0;
}