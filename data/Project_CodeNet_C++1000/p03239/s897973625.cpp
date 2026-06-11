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
    int n,T,c,t,i;
    cin>>n>>T;
    int ans=1001;
    for (i=0;i<n;i++)
    {
        cin>>c>>t;
        if (t<=T)
            ans=min(ans,c);
    }
    if (ans==1001)
        cout<<"TLE\n";
    else
        cout<<ans<<endl;
}