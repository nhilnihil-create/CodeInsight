#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,i,j,k,m;
    cin>>n;
    int x[n],y[n];
    ll h[n],ex;
    for (i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>h[i];
        if (h[i])
            m=i;
    }
    int cx,cy,f;
    ll H,th;
    for (i=0;i<=100;i++)
    {
        for (j=0;j<=100;j++)
        {
            f=0;
            th=h[m]+abs(x[m]-i)+abs(y[m]-j);
            for (k=0;k<n;k++)
            {
                if (h[k]!=max(th-abs(x[k]-i)-abs(y[k]-j),0LL))
                {
                    f=1;
                    break;
                }
            }
            if (!f)
            {
                cx=i;
                cy=j;
                H=th;
                break;
            }
        }
        if (!f)
            break;
    }
    cout<<cx<<" "<<cy<<" "<<H<<endl;
}