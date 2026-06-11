#include <cstdio>
#include <vector>
using namespace std;

const long long INF=10000000000000000ll;

int main()
{
  int n;
  long long a,b;
  scanf("%d%lld%lld",&n,&a,&b);
  vector<int> p(n+1);
  for(int i=0;i<n;i++){
    scanf("%d",&p[i]);
    p[i]--;
  }
  p[n]=n;
  vector<long long> dp(n+1);
  for(int i=0;i<=n;i++){
    int ca=0,cb=0;
    int k=-1;
    dp[i]=INF;
    for(int j=i-1;j>=0;j--){
      if(p[j]>p[i]){
	ca++;
      }
      else if(k==-1||p[k]<p[j]){
	dp[i]=min(dp[i],dp[j]+ca*a+cb*b);
	cb++;
	k=j;
      }
      else{
	cb++;
      }
    }
    if(k==-1){
      dp[i]=i*a;
    }
  }
  printf("%lld\n",dp[n]);
  return 0;
}
