#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string S;
vector<vector<int>> v(200010);
int N,M,visited[200010] = {0};

int main(){
	cin  >> N >> M >> S;
	int a,b;
	int A[200010] = {0},B[200010] = {0};
	for(int i=0;i<M;i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> Q;
	int count = 0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<v[i].size();j++){
			if(S[v[i][j]-1]=='A') A[i]++;
			if(S[v[i][j]-1]=='B') B[i]++;
		}
		if(A[i]==0 || B[i]==0){
			Q.push(i);
			visited[i] = 1;
			count++;
		}
	}
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		for(int i=0;i<v[t].size();i++){
			if(S[t-1]=='A') A[v[t][i]]--;
			if(S[t-1]=='B') B[v[t][i]]--;
			if((A[v[t][i]]==0 || B[v[t][i]]==0) && visited[v[t][i]]==0){
				Q.push(v[t][i]);
				count++;
				visited[v[t][i]] = 1;
			}
		}
	}
	cout << (count<N? "Yes":"No") << endl;
}