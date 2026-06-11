#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a,b,i,c[2][N];
vector<int>e[N];
char s[N];
bool inq[N];
queue<int>q;
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		e[a].push_back(b),e[b].push_back(a),++c[s[a]-'A'][b],++c[s[b]-'A'][a];
	}
	for(i=1;i<=n;++i)if(!c[0][i] || !c[1][i])q.push(i),inq[i]=1;
	for(;!q.empty();){
		a=q.front();q.pop();
		for(int v:e[a])if(!inq[v] && !--c[s[a]-'A'][v])inq[v]=1,q.push(v);
	}
	for(i=1;i<=n;++i)if(!inq[i])break;
	puts(i<=n?"Yes":"No");
	return 0;
}