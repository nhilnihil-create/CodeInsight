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
    string s;
    cin>>n;
    cin>>s;
    int prew[n]={0},sufe[n]={0};
    prew[0]=(s[0]=='W');
    sufe[n-1]=(s[n-1]=='E');
    for (i=1;i<n;i++)
    {
        prew[i]=prew[i-1]+(s[i]=='W');
        sufe[n-i-1]=sufe[n-i]+(s[n-i-1]=='E');
    }
    int ans=n+1,tp;
    for (i=0;i<n;i++)
    {
        tp=prew[i]-(s[i]=='W')+sufe[i]-(s[i]=='E');
        ans=min(ans,tp);
    }
    cout<<ans<<endl;
}