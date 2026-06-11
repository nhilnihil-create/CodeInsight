#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
  long long int x[200000],xx,sum[200000],ans,b,n;
  scanf("%lld %lld",&n,&xx);
  for(int i=0;i<n;i++)
    scanf("%lld ",&x[i]);
 sum[0]=x[0];
  for(int i=1;i<n;i++)
    sum[i]=sum[i-1]+x[i];
  ans=n*xx+sum[n-1]*5;
  for(long long int i=1;i<=n;i++){
    b=(i)*xx;
    for(long long int j=0;j<n;j+=i){
      if(j==0&&n-1-i>=0)
        b+=5*(sum[n-1-j]-sum[n-j-1-i]);
      else if(j==0)
        b+=5*sum[n-1-j];
      else if(n-j-1-i>=0)
        b+=(2*(j/i+1)+1)*(sum[n-1-j]-sum[n-j-1-i]);
      else
        b+=(2*(j/i+1)+1)*(sum[n-1-j]);
    }
    if(b>0)
      ans=min(ans,b);
  }
  printf("%lld\n",ans+n*xx);
}
