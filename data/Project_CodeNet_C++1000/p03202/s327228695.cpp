#include <bits/stdc++.h>
#define FR first
#define SE second

using namespace std;

typedef pair<int,int> pr;

int num[200005];
pr st[400005];

bool check(int n,int d) {
  int top=0;
  for(int i=1;i<=n;i++)
    if (num[i]>num[i-1]) st[++top]=pr(1,num[i]-num[i-1]);
    else {
    	int len=num[i-1];
    	while (len>num[i])
    	  if (len-st[top].SE>=num[i]) len-=st[top--].SE;
    	  else {
    	  	st[top].SE-=len-num[i];
    	  	break;
		  }
		while (top&&st[top].FR==d) len-=st[top--].SE;
		if (!top) return 0;
		if (st[top].SE>1) {
			st[top].SE--;
			st[++top]=pr(1,1);
		}
		st[top].FR++;
		if (len<num[i]) st[++top]=pr(1,num[i]-len);
	}
  return 1;
}

int main() {
  int n;
  scanf("%d",&n);
  bool v=1;
  for(int i=1;i<=n;i++) {
    scanf("%d",&num[i]);
    if (num[i]<=num[i-1]) v=0;
  }
  if (v) {
  	puts("1");
  	return 0;
  }
  int l=2,r=n;
  while (l<r) {
  	int m=((l+r)>>1);
  	if (check(n,m)) r=m; else l=m+1;
  }
  printf("%d\n",l);
  return 0;
}