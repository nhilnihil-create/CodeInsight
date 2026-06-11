/**
*    created: 24.06.2020 13:39:27
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

    int n, k;
    cin >> n >> k;
    int t = n / k;
    int s = n / (k / 2);
    if (k % 2 == 1) cout << t * t * t << endl;
    else cout << t * t * t + (s-t)*(s-t)*(s-t) << endl;
    return 0;
}