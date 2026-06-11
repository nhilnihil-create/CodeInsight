#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0, b = 0, t = 0;
    cin >> a >> b >> t;
    int ans=0;
    for (int i = a; i < t + 0.5; i += a) {
        ans += b;
    }

    cout << ans << endl;

}