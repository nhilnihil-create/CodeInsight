#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    int64_t k;
    cin >> a >> b >> c >> k;

    int ans = a-b;
    if(k%2 != 0) ans *= -1;

    cout << ans << endl;
}