#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5 + 10;
const int oo = 1e18;

int n, ans;
int a[N], b[N], sum[N];

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i] >> b[i];
        sum[i] = -(a[i] + b[i]);
        ans -= b[i];
    }

    sort(sum + 1, sum + n + 1);
    FOR(i, 1, n) if(i % 2) ans -= sum[i];
    return cout << ans, 0;
}
