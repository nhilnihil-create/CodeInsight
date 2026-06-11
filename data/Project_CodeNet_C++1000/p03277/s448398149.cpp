#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int inf=1000*1000*1000;
int n,a[maxn],t[maxn*2];
void add(int x){
  for(;x<maxn*2;x+=x&-x)t[x]++;
}
int ask(int x){
  int y=0;
  for(;x>0;x-=x&-x)y+=t[x];
  return y;
}
long long chk(int v){
  int sum=maxn;
  long long res=0;
  memset(t,0,sizeof(t));
  add(sum);
  for(int i=1;i<=n;i++){
    sum+=(a[i]<=v)?1:-1;
    res+=ask(sum-1);
    //printf("i %d %d %d\n",i,sum,res);
    add(sum);
  }
  return res;
}
int main(){
  //freopen("aa.in","r",stdin);
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",a+i);
  }
  int l=1,r=inf;
  long long all=1LL*n*(n+1)/2;
  for(;l<r;){
    int mid=(l+r)/2;
    if(chk(mid)<=all/2)l=mid+1;
    else r=mid;
  }
  printf("%d\n",l);
  return 0;
}