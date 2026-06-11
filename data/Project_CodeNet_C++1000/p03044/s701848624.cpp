#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define pb push_back
int main(){
  int n;
  cin>>n;
  vector<P> e[n];
  bool colored[n]={};
  int color[n]={};
  rep(i,n-1){
	int u,v,w;
	cin>>u>>v>>w;
	w%=2;
	u--;v--;
	e[u].pb({v,w});
	e[v].pb({u,w});
  }
  queue<int> q;
  q.push(0);
  while(!q.empty()){
	int i=q.front();
    //cout<<i<<endl;
	q.pop();
	for(auto j:e[i]){
		int t=j.first;
		if(colored[t])continue;
		if(j.second){
			color[t]=color[i]==0?1:0;
		}else{
			color[t]=color[i]==0?0:1;
		}
		q.push(t);
		colored[t]=true;
	}
  }
  rep(i,n){
	cout<<color[i]<<endl;
  }
}
