/**
*    created: 23.06.2020 23:28:27
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (100 <= n && n <= 111) cout << 111 << endl;
    if (111 < n && n <= 222) cout << 222 << endl;
    if (222 < n && n <= 333) cout << 333 << endl;
    if (333 < n && n <= 444) cout << 444 << endl;
    if (444 < n && n <= 555) cout << 555 << endl;
    if (555 < n && n <= 666) cout << 666 << endl;
    if (666 < n && n <= 777) cout << 777 << endl;
    if (777 < n && n <= 888) cout << 888 << endl;
    if (888 < n && n <= 999) cout << 999 << endl;
    return 0;
}