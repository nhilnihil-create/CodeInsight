
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
int k;


int mydp(int i)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int ret1=INF;
    //cout<<i<<endl;
    for(int j=i+1;j<=min(n,i+k);j++)
    {
      //  cout<<"asdf"<<endl;
        ret1=min(ret1,abs(arr[i]-arr[j])+mydp(j));
    }
    //cout<<ret1<<endl;
    dp[i]=ret1;
    return dp[i];
}
int main()
{

   //  #ifndef ONLINE_JUDGE
   //    freopen("input.txt","r",stdin);
   //    freopen("output.txt","w",stdout);
  //   #endif

  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
      cin>>arr[i];
  }
  for(int i=0;i<=100000;i++)
  {
      dp[i]=-1;
  }
  int ans=mydp(1);
  cout<<ans<<endl;
}

