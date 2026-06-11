#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
vector<pii>l_list[100005];
int check[100005];
int d[100005];
int DFS(int x,int ct){
	check[x]=ct==MOD?1:2;
	d[x]=ct;
	for(auto &p:l_list[x]){
		if(check[p.F]==1)continue;
		else if(check[p.F]==2){
			if(d[x]==MOD){
				d[x]=d[p.F]-p.S;
				check[x]=2;
			}
			else{
				if(d[x]!=d[p.F]-p.S)return -MOD;
			}
		}
		else{
			if(check[x]<2){
				int t=DFS(p.F,MOD);
				if(t==-MOD)return -MOD;
				if(d[x]==MOD){
					d[x]=t-p.S;
					check[x]=2;
				}
				else{
					if(d[x]!=t-p.S)return -MOD;
				}
			}
			else{
				int t=DFS(p.F,d[x]+p.S);
				if(t==-MOD)return -MOD;
			}
		}
	}
	if(d[x]==MOD)d[x]=0,check[x]=2;
	return d[x];
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int t1,t2,t;
		scanf("%d%d%d",&t1,&t2,&t);
		l_list[t1].pb({t2,t});
		l_list[t2].pb({t1,-t});
	}
	for(int i=1;i<=n;i++){
		if(!check[i]){
			if(DFS(i,MOD)==-MOD)ex("No");
		}
	}
	printf("Yes");
}