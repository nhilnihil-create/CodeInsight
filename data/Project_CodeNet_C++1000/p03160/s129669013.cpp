#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define t1(a) cout << #a << ":" << a << endl;
#define t2(a, b) cout << #a << ":" << a << " | " << #b << ":" << b << endl;
#define t3(a, b, c) cout << #a << ":" << a << " | " << #b << ":" << b << " | " << #c << ":" << c << endl;

using namespace std;
void minCost(int dp[],int H[],int n)
{
    dp[0]=0;
     dp[1]=abs(H[1]-H[0]);
    for(int i=2;i<n;i++)
    {
       // cout<<dp[i-2]+abs(H[i]-H[i-2])<<endl;
        dp[i]=min(dp[i-1]+abs(H[i]-H[i-1]),dp[i-2]+abs(H[i]-H[i-2]));
       // cout<<<<endl;
       // cout<<i<<" "<<dp[i-2]<<endl;
    }
}
int32_t main()
{
   IOS;
   
      int n,m,k,x,y,z,a,b,c,count=0,ans=0,temp=0,flag=0,od=0,ev=0,curr=0,prev=0,left,right,h,g,f;
     cin >> n;
     int H[n];
     int dp[n]={0};
     
     for(int i=0;i<n;i++)
        {
          cin>> H[i];   
        }
      minCost(dp,H,n);
      cout<<dp[n-1];
   
  return 0;
}