#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)

int main()
{  
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   ll n=0,k=0;
   
   cin>>n>>k;
   ll a[n];
   ll dp[k+1]={0};
  
   f(i,0,n)
    cin>>a[i];

   f(i,1,k+1)
    {
      for(auto j : a)
       {
         if((i-j)>=0 && dp[i-j]==0)
            dp[i]=1;
       }
    }

   if(dp[k]==1)
     cout<<"First";
   else cout<<"Second";

  return 0;
}
