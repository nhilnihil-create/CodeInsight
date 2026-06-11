#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
const int N = 1e5 + 5;

int n;
int a[N], b[N], c[N];
int val[N];

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);   cout.tie(0);

    cin >> n;

    int suma = 0, sumb = 0;
    FOR(i, 1, n) cin >> a[i], suma += a[i];

    int ans = 0, sum = 0, cnt = 0;
    FOR(i, 1, n)    {
        cin >> b[i]; sumb += b[i];
        if(a[i] < b[i]) ans ++, sum += b[i] - a[i];
        if(a[i] > b[i]) val[++cnt] = a[i] - b[i];
    }

    if(suma < sumb) return cout << "-1", 0;
    if(sum == 0) return cout << "0", 0;

    sort(val + 1, val + cnt + 1);
    for(int i = cnt; i >= 1; --i)   {
        val[i] += val[i + 1];
        ans ++;
        if(val[i] >= sum) return cout << ans, 0;
    }
}
