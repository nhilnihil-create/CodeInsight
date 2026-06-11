#include <stdio.h>
#include <vector>
using namespace std;
const int N=1e5+10;
#define PB push_back
vector<int> graph[N];
int val[N];
bool dfs(int now){
	for(int i:graph[now]){
		if(val[i]==val[now])return true;
		else if(val[i]==0) {
			val[i]=-val[now];
			if(dfs(i))return true;
		}
	}
	return false;
}
int main(){
	int n,m,l,r;
	long long int ans;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)val[i]=0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		graph[l].PB(r);
		graph[r].PB(l);
	}
	val[1]=1;
	if(dfs(1))ans=(((long long int)n*(long long int)(n-1))>>1)-m;
	else{
		l=r=0;
		for(int i=1;i<=n;i++)if(val[i]==1)l++;
		else r++;
		ans=(long long int)l*(long long int)r-m;
	}
	printf("%lld\n",ans);
}
