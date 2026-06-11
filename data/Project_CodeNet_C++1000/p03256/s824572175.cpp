/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=int(2e5);
vector<int> lnk[2*N+5];
int n,m;
char fla[N+5];
int tag[2*N+5];
void DFS(int u){
	tag[u]=1;
	for(int i=0;i<lnk[u].size();i++){
		int v=lnk[u][i];
		if(tag[v]==0)
			DFS(v);
		if(tag[v]==1){
			printf("Yes\n");
			exit(0);
		}
	}
	tag[u]=-1;
}
int main(){
	scanf("%d%d%s",&n,&m,fla+1);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		if(fla[u]==fla[v]){
			lnk[u].push_back(v+n);
			lnk[v].push_back(u+n);
		}
		else{
			lnk[u+n].push_back(v);
			lnk[v+n].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)
		if(tag[i]==0)
			DFS(i);
	printf("No\n");
	return 0;
}