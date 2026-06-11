#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t as[100005];
int64_t f[100005];

int main(){
  int64_t N;
  scanf("%ld",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%ld",&as[i]);
  }
  f[N]=1;
  for(int64_t i=N;i>0;i--){
    f[i-1]=f[i]*i%MOD;
  }
  int fact=1;
  for(int64_t i=1;i<=N;i++){
    f[i]=f[i]*fact%MOD;
    fact=fact*i%MOD;
  }
  int64_t scale=0;
  for(int64_t i=1;i<=N;i++){
    //printf("f[%ld]=%ld\n",i,f[i]);
    scale=(scale+f[i])%MOD;
  }
  int64_t ans=0;
  for(int64_t i=0;i<N;i++){
    //printf("+%ld*%ld\n",as[i],scale);
    ans=(ans+as[i]*scale)%MOD;
    scale=(scale+MOD-f[N-i]+f[i+2])%MOD;
  }
  printf("%ld\n",ans);
  return 0;
}
