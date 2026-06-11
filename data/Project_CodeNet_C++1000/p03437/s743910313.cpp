#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;


int main()
{
    ll x, y;
    cin >> x >> y;
    if (x%y == 0) cout << -1 << endl;
    else cout << x << endl;
    return 0;
}
