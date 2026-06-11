#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    int n,q;
    cin>>n>>q;
    string a;
    cin>>a;
    a="@"+a;
    char x,y;
    vector<pair<int,int>> qq;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        if(y=='L')
            qq.push_back({x,-1});
        else
            qq.push_back({x,1});
    }

    int mx=0;
    int l=1,r=n;
    while (l<=r)
    {
        int mid=l+(r-l)/2;
        int x=mid;
        bool flag=false;
        for(auto i:qq)
        {
            if(a[x]==i.first)
            {
                x+=i.second;                
            }
            if(x==0)
            {
                flag=true;
                break;
            }
            else if(x==n+1)
            {
                break;
            }
        }
        if(flag)
        {
            l=mid+1;
            mx=max(mx,mid);
        }
        else
        {
            r=mid-1;
        }        
    }
    int mn=n+1;
    l=1,r=n;
    while (l<=r)
    {
        int mid=l+(r-l)/2;
        int x=mid;
        bool flag=false;
        for(auto i:qq)
        {
            if(a[x]==i.first)
            {
                x+=i.second;                
            }
            if(x==n+1)
            {
                flag=true;
                break;
            }
            else if(x==0)
            {
                break;
            }
        }
        if(flag)
        {
            r=mid-1;
            mn=min(mn,mid);
        }
        else
        {
            l=mid+1;
        }        
    }
    int z=mn-mx-1;
    cout<<max(0LL,z);
} 

