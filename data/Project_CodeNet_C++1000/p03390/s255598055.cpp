#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int Q;
LL a,b;
int main(){
  scanf("%d",&Q);
  while(Q--){
    scanf("%lld%lld",&a,&b);
    if(a==b) printf("%lld\n",a*2-2); else{
      if(a>b) swap(a,b);
      LL m=sqrt(a*b),t=(a*b-1)/m-1;
      printf("%lld\n",m-1+t);
    }
  }
  return 0;
}
