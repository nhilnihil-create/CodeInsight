#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN 	= 100001;
const int BIG_NUM = 1000000007;

int N;
int x,y;
vector <int> graph[MAXN];
vector <long long> B,W,vis;

int solve(int root){
	
	if(vis[root])
		return (B[root]+W[root])%BIG_NUM;

	vis[root]=1;
	
	for(auto child : graph[root]){
		if(!vis[child]){
			solve(child);
			B[root] = (B[root]*W[child])%BIG_NUM ;
			W[root] = (W[root]*(W[child] + B[child]))%BIG_NUM ;
		}
	}

	return (B[root]+W[root])%BIG_NUM;
}

int main(){
	cin>>N;

	B.resize(N,1);
	W.resize(N,1);
	vis.resize(N,0);

	for(int i=1;i<N;i++){
		cin>>x>>y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}

	cout<<solve(0)<<endl;
}
