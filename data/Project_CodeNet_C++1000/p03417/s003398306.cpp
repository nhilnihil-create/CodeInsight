#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 50005

int main()
{
    _FastIO;
    ll n , m;
    cin >> n >> m;
    if(n >= 2)
        n -= 2;
    if(m >= 2)
        m -= 2;
    ll ans = n * m;
    cout << ans << endl;
    return 0;
}
