#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const ll INF = 1e15;

using namespace std;

int F[110][20];
ll P[110][20];

main()
{
    fast;
    int n,i,j,k;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=10;j++)
            cin>>F[i][j];
    }
    for (i=1;i<=n;i++)
    {
        for (j=0;j<=10;j++)
            cin>>P[i][j];
    }
    int p,ctr;
    ll ans=-INF;
    for (k=1;k<(1<<10);k++)
    {
        p=k;
        ctr=10;
        int mark[11]={0};
        while (ctr>0)
        {
            if (p&1)
                mark[ctr]=1;
            else
                mark[ctr]=0;
            ctr--;
            p>>=1;
        }
        ll tp=0;
        for (i=1;i<=n;i++)
        {
            int cnt=0;
            for (j=1;j<=10;j++)
            {
                if (F[i][j]==1 && mark[j]==1)
                    cnt++;
            }
            tp+=P[i][cnt];
        }
        ans=max(tp,ans);
    }
    cout<<ans<<endl;
}