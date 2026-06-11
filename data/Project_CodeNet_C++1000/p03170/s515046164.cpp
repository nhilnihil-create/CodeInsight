#include<bits/stdc++.h>


#define ll long long int
#define pb push_back
#define F first
#define S second 
#define f(i,n) for(int i = 0; i < n; i++)
using namespace std;
    // n   sum


bool solve(int n,int k, int a[])
{
  bool dp[k+1];
 // memset(dp,false,sizeof(dp));
  
  for(int j = 0; j <= k ; j++)
  { dp[j] = false;
    for(int i = 0; i < n; i++)
    {
      if(j >= a[i] && !dp[j - a[i]])
        dp[j] = true;
    }
  }
  return dp[k];
}







int main()
{
 
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     //soe();
     int n,k; cin>>n>>k;
     int a[n];
     
     f(i,n)
       cin>>a[i];
     
      
     
     solve(n,k,a)?cout<<"First"<<endl:cout<<"Second"<<endl;

     return 0;
}