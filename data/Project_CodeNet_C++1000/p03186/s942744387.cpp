#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, CC = 10001;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a + b >= c - 1)
        cout << b + c;
    else
        cout << 2 * b + a + 1;
    return 0;
}
