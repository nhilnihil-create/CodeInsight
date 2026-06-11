#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

string S;
vector<vector<int>> v(400010);
int N,M,visited[400010] = {0};

void dfs(int n){
	visited[n] = -1;
	for(int i=0;i<v[n].size();i++){
		if(visited[v[n][i]]==-1){
			cout << "Yes" << endl;
			exit(0);
		}
		else if(visited[v[n][i]]==0) dfs(v[n][i]);
	}
	visited[n] = 1;
}

int main(){
	cin  >> N >> M >> S;
	int a,b;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		if(S[a-1]==S[b-1]){
			v[a].push_back(b+N);
			v[b].push_back(a+N);
		}else{
			v[a+N].push_back(b);
			v[b+N].push_back(a);
		}
	}
	for(int i=1;i<=N;i++){
		if(visited[i]==0) dfs(i);
	}
	cout << "No" << endl;
}