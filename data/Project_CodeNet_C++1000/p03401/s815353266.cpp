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
    int n,i;
    cin>>n;
    int p[n+2],cost=0;
    p[0]=p[n+1]=0;
    for (i=1;i<=n;i++)
    {
        cin>>p[i];
        cost+=abs(p[i]-p[i-1]);
    }
    cost+=abs(p[n+1]-p[n]);
    for (i=1;i<=n;i++)
        cout<<cost-abs(p[i]-p[i-1])-abs(p[i+1]-p[i])+abs(p[i+1]-p[i-1])<<endl;
}