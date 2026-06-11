#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 1e2+5;

ll n , a[N] , cost[N][15] , ans=-1e18;

void solve(int bt , int cur)
{
    if (bt == 10)
    {
        ll sum=0 , tmp , c;
        c = __builtin_popcount(cur);
        if (c == 0) return;

        for(int i=1; i<=n; i++)
        {
            tmp = cur&a[i];
            c = __builtin_popcount(tmp);
            sum += cost[i][c];
        }
        ans = max(ans , sum);
        return;
    }

    solve(bt+1 , cur);
    solve(bt+1 , cur|(1<<bt));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<10; j++)
        {
            int x;
            cin >> x;
            if (x) a[i] |= (1<<j);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<11; j++)
            cin >> cost[i][j];
    }

    solve(0,0);
    cout << ans << "\n";

    return 0;
}