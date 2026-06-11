#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define l first
#define r second

using namespace std;

const int maxn = 3e5 + 1;

bool usd[101][101];
int n, a, b;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    if (abs(a - b) % 2 == 0) {
        cout << "Alice";
        return 0;
    } else {
        cout << "Borys";
        return 0;
    }
    return 0;
}
