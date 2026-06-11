#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back

typedef long long llo;
llo n,m;
vector<llo> adj[100001];
llo val[100001];
llo st=1;
llo co[3];
void dfs(llo no,llo ac=1){
	val[no]=ac;
	co[ac]+=1;
	for(auto j:adj[no]){
		if(val[j]==0){
			dfs(j,3-ac);
		}
		else{
			if(val[j]==val[no]){
				st=0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	llo ans;
	if(st==0){
		ans=((n*(n-1)))/2-m;
	}
	else{
		ans=co[1]*co[2]-m;
	}
	cout<<ans<<endl;



	return 0;
}