#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll X, Y;
    cin >> X >> Y;
    if(X % Y == 0) {
        cout << -1 << "\n";
        return 0;
    } else
        cout << X << "\n";
    return 0;
}
