#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int c[maxn],num[maxn]={0},cnt=0,head[maxn<<1];
struct node{
	int next,to;
}e[maxn<<1];
void add(int u,int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
queue<int>que;
int w[maxn];
int vis[maxn]={0};
int main()
{
	int n;
	int maxx=0;
	int now;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		num[a]++;
		num[b]++;
	}
	for(int i=1;i<=n;i++){
		if(num[i]>maxx){
			maxx=num[i];
			now=i;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	int nownum=n;
	que.push(now);
	ll sum=0;
	if(n==1){
		printf("0\n%d\n",c[1]);
		return 0;
	}
	while(!que.empty()){
		int u=que.front();
		vis[u]=1;
		w[u]=c[nownum];
		nownum--;
		que.pop();
		for(int i=head[u];i;i=e[i].next ){
			int v=e[i].to;
			if(vis[v]){
				sum+=min(w[v],w[u]);
				continue;
			}
			que.push(v);
		}
	}
	printf("%lld\n",sum);
	printf("%d",w[1]);
	for(int i=2;i<=n;i++){
		printf(" %d",w[i]);
	}
}