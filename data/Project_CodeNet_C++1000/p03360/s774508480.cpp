#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    vector<int> c(3);
    for (int i = 0; i < 3; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    int k; cin >> k;

    int ans = 0;
    ans += c[0] + c[1];
    for (int i = 0; i < k; i++) {
        c[2] *= 2;
    }
    ans += c[2];

    cout << ans << endl;
    return 0;
}