#include<iostream>
#include<vector>
const int N=2e5+2;
using namespace std;
vector<int> adj[N];
int max1=0,opt[N];
void dfs(int x,int p){
	int j=0;
	for(int i=0;i<adj[x].size();i++){
		if(adj[x][i]!=p){
			dfs(adj[x][i],x);
			if(opt[adj[x][i]]+1>=opt[x]){
				j=opt[x];
				opt[x]=opt[adj[x][i]]+1;
			}
			else{
				if(opt[adj[x][i]]+1>j){
					j=opt[adj[x][i]]+1;
				}
			}
		}
	}
	max1=max(max1,j+opt[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l;
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	dfs(1,1);
	//cout<<max1<<endl;
	if(max1%3==1){
		cout<<"Second";
	}
	else{
		cout<<"First";
	}
}