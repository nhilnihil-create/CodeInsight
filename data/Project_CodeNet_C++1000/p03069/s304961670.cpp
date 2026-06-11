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
    string s;
    cin>>s;
    int bl[n]={0},wh[n]={0};
    for (i=0;i<n;i++)
    {
        if (s[i]=='#')
            bl[i]++;
        else
            wh[i]++;
        if (i!=0)
            bl[i]+=bl[i-1];
    }
    for (i=n-2;i>=0;i--)
        wh[i]+=wh[i+1];
    int ans=n;
    for (i=0;i<n-1;i++)
        ans=min(ans,bl[i]+wh[i+1]);
    ans=min(ans,bl[n-1]);
    ans=min(ans,wh[0]);
    cout<<ans<<endl;
}