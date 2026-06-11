/**
*    created: 21.06.2020 02:45:51
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

    int a, b;
    cin >> a >> b;
    if (a % 2 == 0 || b % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}