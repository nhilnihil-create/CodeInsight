#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, q;
int a[N], b[N];

int cost(int x, int p, int q)
{
    return abs(x-p) + abs(p-q);
}

int32_t main()
{
    IOS;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    while(q--)
    {
        int ans=1e18;
        int x;
        cin>>x;
        int idx1=lower_bound(a+1, a+n+1, x) - a;
        int idx2=lower_bound(b+1, b+m+1, x) - b;
        for(int i=max(1LL, idx1-2);i<=min(n, idx1+2);i++)
        {
            for(int j=max(1LL, idx2-2);j<=min(m, idx2+2);j++)
            {
                ans=min(ans, cost(x, a[i], b[j]));
                ans=min(ans, cost(x, b[j], a[i]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
