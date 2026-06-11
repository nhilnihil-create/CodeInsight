/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
bool f[200000+20];
vector<int> g[200000];
void dfs(vector<int>  &v,int now,vector<bool>& vis){
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]){
			v[it]=v[now]+1;
			dfs(v,it,vis);
		}
	}
}
int main(){
	fastio;
	int n;
	cin>>n;
	rep(i,n-1){
		int ai,bi;
		cin>>ai>>bi;
		ai--;
		bi--;
		g[ai].PB(bi);
		g[bi].PB(ai); 
	}
	vector<int> dis;
	int x,y;
	dis=vector<int> (n,0);
	vector<bool> tmp=vector<bool>(n,0);
	dfs(dis,0,tmp);
	x=0;
	rep(i,n)
	if(dis[i]>dis[x]) x=i;
	dis=vector<int> (n,0);
	tmp=vector<bool>(n,0);
	dfs(dis,x,tmp);
	y=x;
	rep(i,n)
	if(dis[i]>dis[y]) y=i;
	int len=dis[y];
	f[0]=1;
	f[1]=0;
	rep(i,len+1)
	{
		if(i<2) continue;
		rb(j,1,2){
			if(i>=j){
				f[i]|=(!f[i-j]);
			}
		}
//		cout<<f[i]<<endl;
	}
	cout<<(f[len]? "First":"Second")<<'\n'; 
	return 0;
}
