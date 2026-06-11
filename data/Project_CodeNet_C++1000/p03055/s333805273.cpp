#include <bits/stdc++.h>    
#define pb push_back

#define FOR(x,to) for(int x=0;x<(to);x++)
#define F0R(x,in,to) for(int x=(in);x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

typedef long long ll;
using namespace std;
ll MOD = 998244353;

typedef pair<int,int> ii;
typedef struct {int a,b,c;}iii;
typedef vector<int> vi;

void mosA(vector<int> a){
	for(int i=0; i<a.size(); i++) printf("%d ",a[i]);
	printf("\n");
}
void mosP(vector<ii> a){
	for(int i=0; i<a.size(); i++) printf("%d %d\n",a[i].first,a[i].second);
	printf("\n");
}

ll min_especial(ll a, ll b){
  if(a!=-1 && b!=-1) return min(a,b);
  else return max(a,b);
}
/*
bool ord(ii a, ii b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}*/

bool ord(ll a, ll b){
	return a>b;
}

int ans = 0;
int a,n,nn,w,t,k,m,z,q,l,r,x,b,y;
char A[200005],B[200005];
vi G[200005];

ii dfs(int v, int ant){
	if(G[v].size()==1 && ant!=-1) return {0,v};
	ii ans; ans.first=0;
	for(auto u:G[v]){
		if(u==ant) continue;
		ii aux = dfs(u,v);
		if(aux.first>=ans.first)
			ans = aux;
	}
	ans.first++;
	return ans;
}


int main(){
	scanf("%d",&n);
	FOR(i,n-1){
		scanf("%d%d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}

	if(n==1) return!printf("First\n");

	int v = dfs(1,-1).second;
	int l = dfs(v,-1).first;

	//cout<<v<<" "<<l<<endl;
	
	if(l%3==0) return!printf("First\n");
	if(l%3==1) return!printf("Second\n");
	if(l%3==2) return!printf("First\n");


}




// REVISATE ESTO:
// - memset(A,-1,SIZEOF()*n)
// - (x-y+MOD)%MOD
// - int o ll?