#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string n; cin >> n;

    int ans = 0;
    rep(i, n.size()) {
        if (n.at(i) == '2')
            ans++;
    }
    cout << ans << endl;
    return 0;
}