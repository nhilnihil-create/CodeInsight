#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{


    ll n,m,k;
    cin>>n>>m>>k;
    ll arr[m+5]={0};
    ll vis[105]={0};
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
        vis[arr[i]]=1;
    }
    ll cnt=0;
    ll arek=0;
    for(int i=k;i<=n;i++)
    {
        if(vis[i]==1)
        {
            cnt++;
        }

    }
    for(int i=k;i>=0;i--)
    {
        if(vis[i]==1)
        {
            arek++;
        }
    }
    cout<<min(cnt,arek)<<endl;


}
