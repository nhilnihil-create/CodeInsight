#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=10000;

int n,a[N+9];
struct side{
  int y,next;
}e[N*2+9];
int lin[N+9],cs;

void Ins(int x,int y){e[++cs].y=y;e[cs].next=lin[x];lin[x]=cs;}
void Ins2(int x,int y){Ins(x,y);Ins(y,x);}

int deg[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<n;++i){
	int x,y;
	scanf("%d%d",&x,&y);
	Ins2(x,y);
	++deg[x];++deg[y];
  }
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

int ans0,ans[N+9];
queue<int>q;

void Get_ans(){
  sort(a+1,a+n+1);
  for (int i=1;i<=n;++i)
	if (deg[i]==1) q.push(i);
  for (int i=1;!q.empty();++i){
	int t=q.front();q.pop();
	ans[t]=a[i];
	for (int i=lin[t];i;i=e[i].next){
	  if (!ans[e[i].y]) ans0+=ans[t];
	  if (--deg[e[i].y]==1) q.push(e[i].y);
	}
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans0);
  for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
  puts("");
}

int main(){
  into();
  work();
  outo();
  return 0;
}