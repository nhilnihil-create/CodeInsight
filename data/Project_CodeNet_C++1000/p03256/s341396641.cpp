#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;

int n,m;
string s;
vector<int> G[200001];
bool deleted[200001];
int num[2][200001];

void add_edge(int a,int b){
	a--; b--;
	G[a].PB(b);
	if(a!=b) G[b].PB(a);
}

void dfs(int k){
	if((num[0][k]==0||num[1][k]==0)&&(!deleted[k])){
		deleted[k]=true;
		FOR(i,0,G[k].size()){
			if(!deleted[G[k][i]]){
				num[s[k]-'A'][G[k][i]]--;
				dfs(G[k][i]);
			}
		}
	}
}

int main(){
	cin>>n>>m>>s;
	FOR(i,0,m){
		int a,b; cin>>a>>b;
		add_edge(a,b);
	}
	FOR(i,0,n){
		FOR(j,0,G[i].size()){
			num[s[G[i][j]]-'A'][i]++;
		}
	}
	FOR(i,0,n){
		dfs(i);
	}
	bool flag=false;
	FOR(i,0,n){
		if(!deleted[i]) flag=true;
	}
	Yes(flag);
}
