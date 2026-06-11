#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num[5005],pos[5005],cnt[5005];
ll f[5005][5005];

int main() {
  memset(f,0x3f,sizeof(f));
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  for(int i=1;i<=n;i++) {
  	scanf("%d",&num[i]);
  	pos[num[i]]=i;
  }
  for(int i=0;i<=n;i++) f[i][0]=f[0][i]=0;
  for(int i=1;i<=n;i++) {
  	for(int j=num[i]+1;j<=n;j++)
  	  if (pos[j]<i) cnt[j]++;
    for(int j=1;j<=n;j++)
      if (pos[j]<=i) {
      	if (!cnt[j]) f[i][j]=f[i][j-1];
      	else f[i][j]=min(f[i][j-1]+a,f[pos[j]-1][j]+(ll)b*cnt[j]);
	  }
      else f[i][j]=f[i][j-1];
  }
  printf("%lld\n",f[n][n]);
  return 0;
}