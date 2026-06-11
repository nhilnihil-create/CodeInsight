#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
int d[200010], l[200010], r[200010], x[200010];
bool det[200010];

bool dfs(int key){
	det[key]=true;
	bool res=true;
	for(int i=0; i<G[key].size(); ++i){
		int antic=x[key], nx=l[G[key][i]]+r[G[key][i]]-key;
		if(l[G[key][i]]==key) antic += d[G[key][i]];
		else antic -= d[G[key][i]];
		if(det[nx]){
			res=res&&(x[nx]==antic);
		}else{
			x[nx]=antic;
			res=res&&dfs(nx);
		}
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;
	G.resize(N+1);
	for(int i=0; i<M; ++i){
		cin >> l[i] >> r[i] >> d[i];
		G[l[i]].emplace_back(i);
		G[r[i]].emplace_back(i);
	}
	bool flag=true;
	for(int i=1; i<=N; ++i){
		if(!det[i]){
			x[i]=0;
			flag=flag&&dfs(i);
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}