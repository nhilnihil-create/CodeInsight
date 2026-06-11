#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int N, M;
int p[100005];
ll dist[100005];
int find(int a){
	if(a==p[a]) return a;
	int pa=p[a];
	p[a]=find(pa);
	dist[a]+=dist[pa];
	return p[a];
}
bool merge(int a,int b,int d){
	int pa=find(a), pb=find(b);
	if(pa==pb){
		return dist[a]==dist[b]+d;
	}
	else{
		p[pa]=pb;
		dist[pa]=d-dist[a]+dist[b];
		return 1;
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
		p[i]=i;
	while(M--){
		int L,R,D; scanf("%d %d %d",&L,&R,&D);
		if(!merge(L,R,D)) return !printf("No");
	}
	puts("Yes");

}