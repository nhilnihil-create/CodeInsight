
//In the Name of Allah Most Gracious, Most Merciful//
/*If you want something you've never had, you have  to do something you never did.*/

#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 100007
#define INF 1e9
#define INFL 1e18
#define PI acos(-1)
#define mp make_pair

//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
int n;
int dp[100100];
int arr[100100];



int mydp(int i)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int ret1=INF,ret2=INF;
    if(i+2<=n)
    {
        ret1=abs(arr[i+2]-arr[i])+mydp(i+2);
    }
    if(i+1<=n)
    {
        ret2=abs(arr[i+1]-arr[i])+mydp(i+1);
    }
    dp[i]=min(ret1,ret2);
    return dp[i];
}
int main()
{

   //  #ifndef ONLINE_JUDGE
   //    freopen("input.txt","r",stdin);
   //    freopen("output.txt","w",stdout);
  //   #endif
  cin>>n;
  for(int i=1;i<=n;i++)
  {
      cin>>arr[i];
  }
  dp[0]=0;
  dp[1]=0;
//  for(int i=0;i<=100000;i++)
//  {
//      dp[i]=INF;
//  }
  arr[0]=arr[1];
  dp[0]=0;
  dp[1]=0;
  for(int i=2;i<=n;i++)
  {

      dp[i]=dp[i-1]+abs(arr[i]-arr[i-1]);
      if(i-2>=1)
      {
          dp[i]=min(dp[i],dp[i-2]+abs(arr[i]-arr[i-2]));
      }
  }
  cout<<dp[n]<<endl;


}

