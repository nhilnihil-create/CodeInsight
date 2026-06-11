#include<bits/stdc++.h>
const int N=200001;
int n;
int a[N];
int sum[N];
long long c[N<<1];
long long ask(int x){
	long long ans=0;
	for(;x;x-=x&(-x))
	  ans+=c[x];
	return ans;
}
void change(int x,int y){
	for(;x<=3*n;x+=x&(-x))
	  c[x]+=y;
}
int check(int x){
  long long ans=0;
  memset(sum,0,sizeof(sum));
  for(int i=1;i<=n;++i)
    sum[i]=(a[i]<=x?1:-1);
  for(int i=1;i<=n;++i)
    sum[i]+=sum[i-1];
  for(int i=0;i<=n;i++)
    sum[i]+=n+1;
  memset( c , 0 , sizeof c );
  for(int i=0;i<=n;i++){
    ans+=ask(sum[i]-1);
    change(sum[i],1);
  }
  return ans>=1ll*n*(n+1)/2/2+1;
}
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  int l=0,r=1e9;
  int answer=0;
  while(l<=r){
    int mid=l+r>>1;
    if(check(mid))
      r=mid;
    else
      l=mid+1;
    if(r-l<=1){
      answer=check(l)?l:r;
      goto shit;
    }
    answer=mid;
  }
  shit:;
  printf("%d\n",answer);
  return 0;
}