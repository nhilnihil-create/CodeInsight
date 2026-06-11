#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define llceil(a, b) ((ll)a + ((ll)b - 1)) / (ll)b

int main()
{
    ll n, a, b ,c ,d, e;
    cin >> n >> a >> b >> c >> d >> e;

    ll ans = llceil(n, min(min(min(a, b), c),min(d, e))) + 4;
    cout << ans << endl;
    return 0;
}