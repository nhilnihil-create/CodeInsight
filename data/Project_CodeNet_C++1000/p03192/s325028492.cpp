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
    int i,ans=0;
    string n;
    cin>>n;
    for (i=0;i<n.size();i++)
        ans+=(n[i]=='2');
    cout<<ans<<endl;
}