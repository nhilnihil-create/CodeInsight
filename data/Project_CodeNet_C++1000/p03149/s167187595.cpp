#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {

    bool flag[10] = {false};

    rep(i, 4) {
        int a;
        cin >> a;
        flag[a] = true;
    }

    if (flag[1] && flag[9] && flag[7] && flag[4])
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}