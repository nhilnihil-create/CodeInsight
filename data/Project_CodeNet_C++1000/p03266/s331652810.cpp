#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 2e5+10;

using namespace std;

main()
{
    fast;
    int n,k,i;
    cin>>n>>k;
    int mark[N]={0};
    for (i=1;i<=n;i++)
        mark[i%k]++;
    ll ans=pow(mark[0],3);
    if (k%2==0)
        ans+=pow(mark[k/2],3);
    cout<<ans<<endl;
}