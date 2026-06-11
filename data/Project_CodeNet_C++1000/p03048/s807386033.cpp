#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=3000;

int n,a[3];

void into(){
  scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
}

LL dp[N+9];

void Get_dp(){
  dp[0]=1;
  for (int i=0;i<3;++i)
	for (int j=a[i];j<=n;++j) dp[j]+=dp[j-a[i]];
}

void work(){
  Get_dp();
}

void outo(){
  printf("%lld\n",dp[n]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}