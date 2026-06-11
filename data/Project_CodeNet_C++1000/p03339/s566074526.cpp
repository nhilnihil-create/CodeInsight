#include<bits/stdc++.h>
using namespace std;

#define int long long int 


int32_t main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int w,e;
    w=e=0;
    for(int i=1;i<str.size();i++)
    {
        if(str[i]=='E')
        e++;
    }
     int ans=INT_MAX;
     for(int i=0;i<n;i++)
     {
         ans=min(ans,w+e);
         if(i==n-1)
         break;
         if(str[i]=='W')w++;
         if(str[i+1]=='E')e--;
     }
     cout<<ans<<endl;
}