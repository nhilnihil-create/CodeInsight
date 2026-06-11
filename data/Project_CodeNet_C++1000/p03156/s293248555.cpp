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
    int a,b;
    cin>>a>>b;
    int s[n+1];
    for(int i=1;i<=n;i++)
        cin>>s[i];
    int x=0,y=0,z=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]<=a)
            x++;
        else if(s[i]>b)
            z++;
        else
        {
            y++;
        }
        
    }
    cout<<min({x,y,z});

} 
    
 
