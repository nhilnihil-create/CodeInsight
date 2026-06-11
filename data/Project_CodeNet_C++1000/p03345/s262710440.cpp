#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define int long long

const int maxn = 5e5 + 1;

using namespace std;

int n;
string s;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << (a - b) * (k % 2 ? -1 : 1) << '\n';
    return 0;
}
