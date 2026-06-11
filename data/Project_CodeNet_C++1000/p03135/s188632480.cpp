#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

ll t , x;

int main()
{
    _FastIO;
    cout.precision(10);
    cin >> t >> x;
    long double ans = t * 1.0 / x * 1.0;
    cout << fixed << ans << endl;
    return 0;
}
