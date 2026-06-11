#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=10000,M=10;

int n,c[N+9][2],ans;
char s[M+9];

void into(){
  scanf("%d",&n);
  int c0=0,c1=0,flag=1;
  for (int i=1;i<=n;++i){
	scanf("%s",s+1);
	int m=strlen(s+1);
	for (int j=1;j<m;++j)
	  if (s[j]=='A'&&s[j+1]=='B') ++ans;
    c0+=s[1]=='B';c1+=s[m]=='A';
	if (s[1]=='B'^s[m]=='A') flag=0;
  }
  ans+=min(c0,c1);
  if (c0&&c1) ans-=flag;
}

void work(){
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