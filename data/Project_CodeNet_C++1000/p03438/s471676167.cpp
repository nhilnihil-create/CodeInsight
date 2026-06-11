#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5 + 10;
const int oo = 1e18;
const int mod = 1e9 + 7;

int n, suma, sumb;
int a[N], b[N];

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);

    cin >> n;

    bool flag = true;
    FOR(i, 1, n)   cin >> a[i], suma += a[i];
    FOR(i, 1, n)    {
        cin >> b[i], sumb += b[i];
        if(b[i] != a[i]) flag = false;
    }
    if(suma > sumb) return cout << "No", 0;
    if(suma == sumb)  return cout << ((flag) ? "Yes" : "No"), 0;

    int cnt = sumb - suma; //cout << cnt << '\n';
    FOR(i, 1, n) if(b[i] > a[i])   cnt -= (b[i] - a[i] + 1) / 2;
    return cout << ((cnt >= 0) ? "Yes" : "No"), 0;
}
