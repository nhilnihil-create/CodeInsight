#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n;

void into(){
  scanf("%lld",&n);
}

LL ans;

void Get_ans(){
  for (LL l=1,r;l<=n;l=r+1){
	r=min(n/(n/l),n);
	LL t=n/l;
	if (n%t) continue;
	t=n/t-1;
	ans+=(l<=t&&t<=r)*t;
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}