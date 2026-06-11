#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans;
    do {
        if (n % 2 == 0) {
            ans += '0';
        } else {
            ans += '1';
            n -= 1;
        }
    } while (n /= -2);

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}
