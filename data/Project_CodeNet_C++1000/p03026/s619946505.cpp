/*Lucky_Glass*/
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=10000;
typedef pair<int,int> pii;
#define fir first
#define sec second

int n;
vector<int> lnk[N+3];
priority_queue< pii > que;
int du[N+3],num[N+3],ans[N+3];
long long tot;
bool del[N+3];

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		lnk[u].push_back(v);
		lnk[v].push_back(u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
		que.push(make_pair(-(du[i]=lnk[i].size()),i));
	for(int t=1;t<=n;t++){
		while(del[que.top().sec]) que.pop();
		int u=que.top().sec;que.pop();
		del[u]=true;
		ans[u]=num[t];
		for(int i=0;i<lnk[u].size();i++){
			int v=lnk[u][i];
			if(del[v]) continue;
			tot+=num[t];
			que.push(make_pair(-(--du[v]),v));
		}
	}
	printf("%lld\n",tot);
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
		if(i==n) printf("\n");
		else printf(" ");
	}
	return 0;
}