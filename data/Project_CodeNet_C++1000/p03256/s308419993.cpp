#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=200005;
int n,m;
char s[maxn];
vector<int>edge[maxn];
queue<int>q;
int cntA[maxn],cntB[maxn];
bool bad[maxn];

int main(){
	scanf("%d%d%s",&n,&m,s+1);
	REP(i,m){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
		if(s[u]=='A')cntA[v]++;
		else cntB[v]++;
		if(s[v]=='A')cntA[u]++;
		else cntB[u]++; 
	}
	REP(i,n)if(!cntA[i]||!cntB[i])q.push(i),bad[i]=true;
	while(!q.empty()){
		int x=q.front();q.pop();
		rep(i,int(edge[x].size())){
			int y=edge[x][i];
			if(s[x]=='A')cntA[y]--;
			else cntB[y]--;
			if(!cntA[y]||!cntB[y]){
				if(!bad[y]){
					bad[y]=true;
					q.push(y);
				}
			}
		}
	}
	REP(i,n)if(!bad[i]){
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
} 