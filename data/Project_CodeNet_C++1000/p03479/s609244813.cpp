
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    int ans = 1;
    while (1) {
        ll c = a << 1;
        if (c < a) break;
        if (c <= b) {
            ++ans;
            a = c;
        } else {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}

