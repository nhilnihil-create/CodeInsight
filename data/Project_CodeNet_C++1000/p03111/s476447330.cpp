#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int INF = 1e6;

using namespace std;

int n,a,b,c;
int l[10];

int solve (int at, int bt, int ct, int cur)
{
    if (cur==n)
    {
        if (min({at,bt,ct})>0)
            return abs(a-at)+abs(b-bt)+abs(c-ct)-30;
        else
            return INF;
    }
    int r1=solve(at,bt,ct,cur+1);
    int r2=solve(at+l[cur],bt,ct,cur+1)+10;
    int r3=solve(at,bt+l[cur],ct,cur+1)+10;
    int r4=solve(at,bt,ct+l[cur],cur+1)+10;
    return min({r1,r2,r3,r4});
}

main()
{
    fast;
    int i;
    cin>>n>>a>>b>>c;
    for (i=0;i<n;i++)
        cin>>l[i];
    int ans=solve(0,0,0,0);
    cout<<ans<<endl;
}