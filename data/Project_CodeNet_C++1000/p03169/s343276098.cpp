#include <iostream>
#include <cstring>
#define eps 0
using namespace std;
typedef long long int ll;
typedef long double lld;
lld dp[500][500][500];
ll n,a;
ll as[4];
lld dfs(ll,ll,ll);
int main() {
  scanf("%lld",&n);
  
  for(int i = 0; i < n; i++)
  {
    scanf("%lld",&a);
    as[a]++;
  }
  //start 
  //cout <<as[1]<<" "<<as[2]<<" "<<as[3]<<endl;
  lld ans = dfs(as[1],as[2],as[3]);
  printf("%.9Lf\n",ans);
}
lld dfs(ll a,ll b,ll c)
{
  if(a<=eps&&b<=eps&&c<=eps)return 0;
  if(dp[a][b][c]>eps)return dp[a][b][c];

  lld res;
  res = 1;
  if(a>0)res+=dfs(a-1,b,c)*(1.0*a)/(1.0*n);
  if(b>0)res+=dfs(a+1,b-1,c)*(1.0*b)/(1.0*n);
  if(c>0)res+=dfs(a,b+1,c-1)*(1.0*c)/(1.0*n);
  return dp[a][b][c] = res*n*1.0/(a+b+c);

}