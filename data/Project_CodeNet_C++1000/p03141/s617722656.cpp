#include<bits/stdc++.h>
#define int long long
using namespace std;


bool comp(pair<int,int>x,pair<int,int>y)
{
    return x.first+x.second>y.first+y.second;
}

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif      

    int n;
    cin>>n;
    pair<int,int>p[n];
    set<pair<int,int> >s[2];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,comp);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            ans+=p[i].first;
        else
            ans-=p[i].second;
    }
    cout<<ans;
}
