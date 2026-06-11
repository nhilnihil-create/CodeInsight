#include <bits/stdc++.h>
 
using namespace std;
 
int num[105],ans[105];
bool in[105];
 
int main() {
  memset(in,1,sizeof(in));
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&num[i]);
  for(int i=n;i>0;i--) {
  	int cur=0,s=0;
    for(int j=1;j<=n;j++)
      if (in[j]) {
      	s++;
      	if (num[j]==s) cur=j;
	  }
	if (cur&&num[cur]<=i) {
		ans[i]=num[cur];
		in[cur]=0;
	}
	else {
		puts("-1");
		return 0;
	}
  }
  for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
  return 0;
}
