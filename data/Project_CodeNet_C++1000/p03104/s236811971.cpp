#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pdd;

#define INF 0x7f7f7f
#define mem(a,b) memset(a , b , sizeof(a))
#define FOR(i, x, n) for(int i = x;i <= n; i++)
// const ll mod = 1e9 + 7;
// const int maxn = 1e5 + 10;
// const double eps = 1e-6;


ll yihuo(ll x)
{
    if (x % 4 == 0) {
        return x;
    } else if (x % 4 == 1)
    {
        return 1;
    } else if (x % 4 == 2)
    {
        return x + 1;
    } else if (x % 4 == 3)
    {
        return 0;
    } else
    {
        return 0;
    }
    
}

void solve()
{
    ll A, B;
    cin >> A >> B;
    cout << (yihuo(A - 1) ^ yihuo(B)) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
#ifdef FZT_ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
#endif
    return 0;
}
