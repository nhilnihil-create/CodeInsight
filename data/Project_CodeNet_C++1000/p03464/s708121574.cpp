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

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
            cin>>a[i];
    if(a[n]>2)
    {
        cout<<-1;
        return 0;
    }
    int l=2,r=3;
    int x,y;
    x=2;
    y=3;
    for(int i=n-1;i>=1;i--)
    {
        r-=r%a[i];
        if(r<x)
        {
            cout<<-1;
            return 0;
        }        
        r+=a[i]-1;
        l=l+(a[i]-l%a[i])%a[i];
        if(l>y)
        {
            cout<<-1;
            return 0;
        }
        if(l>r)
        {
            cout<<-1;
            return 0;
        }
        x=l;
        y=r;
    }
    cout<<l<<" "<<r;
} 
