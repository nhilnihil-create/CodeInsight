//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    int ans=0;
    for(auto i:mp)
    {
        if(i.first>i.second)
            ans+=i.second;
        else
            ans+=i.second-i.first;
    }
    cout<<ans;
}