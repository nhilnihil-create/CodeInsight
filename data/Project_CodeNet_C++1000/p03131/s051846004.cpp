#include<bits/stdc++.h>
#define int long long
using namespace std;


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

    int k,a,b;
    cin>>k>>a>>b;
    if(b-a>2)
    {
        if(k<a+1)
        {
            cout<<k+1;
        }
        else
        {
            int z=a;
            k-=a-1;
            int tt=(k/2);
            int ans=a+(tt*(b-a));
            ans+=(k%2);
            cout<<ans;
        }
        
    }   
    else
    {
        int z=k+1;
        cout<<z;
    }
     

}