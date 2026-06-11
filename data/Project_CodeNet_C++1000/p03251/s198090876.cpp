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
    int n,m,x,y,i;
    cin>>n>>m>>x>>y;
    int xi,yi,a;
    cin>>xi;
    for (i=0;i<n-1;i++)
    {
        cin>>a;
        xi=max(xi,a);
    }
    cin>>yi;
    for (i=0;i<m-1;i++)
    {
        cin>>a;
        yi=min(yi,a);
    }
    int st=xi+1,en=yi;
    if (st>en)
        cout<<"War\n";
    else if (en<=x || st>y)
        cout<<"War\n";
    else
        cout<<"No War\n";
}