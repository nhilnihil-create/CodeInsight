#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=2000;

int n,a[N+9],sum;

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	scanf("%d",&a[i]);
	sum+=a[i];
  }
}

bitset<N*N+9>dp;
int ans;

void Get_dp(){
  dp[0]=1;
  for (int i=1;i<=n;++i) dp|=dp<<a[i];
  for (ans=sum>>1;!dp[ans];--ans);
  ans=sum-ans;
}

void work(){
  Get_dp();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}