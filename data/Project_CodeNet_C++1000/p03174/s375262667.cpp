/*
       ()       ()()()()     ()        ()       ()        ()        ()
      ()()      ()     ()    ()()      ()      ()()       ()()      ()
     ()  ()     ()      ()   ()  ()    ()     ()  ()      ()  ()    ()
    ()()()()    ()      ()   ()    ()  ()    ()()()()     ()    ()  ()
   ()      ()   ()     ()    ()      ()()   ()      ()    ()      ()()
  ()        ()  ()()()()     ()        ()  ()        ()   ()        ()

*/
#include <bits/stdc++.h>
#define MOD  (int)(1e9+7)
#define SIZE (int)(1e5+5)
#define all(x) x.begin(),x.end()
#define si(i)  scanf("%d",&i)
#define sf(f)  scanf("%f",&f)
#define pi(i)  printf("%d",i)
#define pd(d)  printf("%lf",d)
#define deb(x) cout<<#x<<" is "<<x<<"\n";
#define lb     lower_bound
#define ub     upper_bound
#define pb     push_back
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
#define IOfast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int64_t exponentiation(int64_t base,int exp)
{
    if (exp == 0)
        return 1;

    if (exp == 1)
        return base;

    int64_t t = exponentiation(base, exp / 2);

    t = (t * t);

    if (exp % 2 == 0)
        return t;
    else
        return base * t;
}

//int in_between;
//vector <int> index[26];
int64_t dp[21][(1<<22)];

int64_t solve(vector<vector<int>>& compatible,int index_men, int women_subset,int n)
{
 if(index_men == n)
 {
   if(women_subset == 0)
    return 1;
   else
    return 0;
 }

 if(dp[index_men][women_subset] !=-1)
   return dp[index_men][women_subset];

 int64_t ans=0;
 int i=0;
 int temp = women_subset;

 while(temp)
 {
  if( (temp & 1) && compatible[index_men][i])
  ans =(ans + solve(compatible,index_men+1,women_subset^(1<<i),n))%MOD;
  temp>>=1;
  i++;
 }
 return dp[index_men][women_subset] = ans;
}

int main()
{
  IOfast;

  int q=1;
  //cin>>q;
  memset(dp,-1,sizeof(dp));
  while(q--)
  {
      int n;
      cin>>n;

      vector<vector<int>> arr(n,vector<int> (n));

      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
          cin>>arr[i][j];
        }

      int64_t ans=solve(arr,0,(1<<n) - 1,n);

      cout<<ans;
      int ola =0;
  }


  return 0;
}
