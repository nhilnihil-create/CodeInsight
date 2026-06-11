#include<bits/stdc++.h> 
using namespace std; 
//python interactive_runner.py python3 local_testing_tool.py 0 -- ./Code
 
#define x first
#define y second
#define rep(i, a,b) for(int i = int(a); i < int(b); ++i)
#define forn(i,b) for(int i = 0; i < int(b); ++i)
int n;
const int MAXN = 200000+9;
vector<vector<int> > adj(MAXN);
int maxa = 0;
int dfs(int node,int parent){
	vector<int> ni;
	forn(j,adj[node].size()){
		int nei = adj[node][j];
		if(nei!=parent){
		   int dis = dfs(nei,node);
		   ni.push_back(dis);
		}
	}
	sort(ni.begin(),ni.end());
	if(ni.size()>1) maxa = max(maxa,ni[ni.size()-1]+ni[ni.size()-2]+2);
	else if(ni.size())maxa = max(maxa,ni[ni.size()-1]+1);
    if(!ni.size()) return 0;
	return ni[ni.size()-1]+1;
	
}
void solve(){
  int n;
  cin>>n;
  forn(j,n-1){
  	int a,b;
  	cin>>a>>b;
  	a--;b--;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  int a = dfs(0,-1);
  //cout<<maxa<<endl;
  if(maxa%3==1){
  	cout<<"Second"<<'\n';
  }
  else{
  	cout<<"First"<<'\n';
  }
}
int main(){
	 solve();
	return 0;
}