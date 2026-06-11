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
    int n,a,sum=0,mx=0,i;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a;
        mx=max(mx,a);
        sum+=a;
    }
    cout<<sum-mx/2<<endl;
}