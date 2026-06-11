#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

int N, M, L, R, D, check = 0;
int loc[100005];
vector<pi> AdjList[100005];

void dfs(int x, int p){
	if (check) return;
	if (p == -1) loc[x] = 0;
	for (auto it : AdjList[x]){
		if (loc[it.first] == -1e9-1){
			loc[it.first] = loc[x] + it.second;
			dfs(it.first,x);
		}
		else if (loc[it.first] != loc[x] + it.second){
			check = 1;
			return;
		}
		if (check == 1) return;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i){
		loc[i] = -1e9-1;
	}
	for (int i = 1; i <= M; ++i){
		cin >> L >> R >> D;
		AdjList[L].push_back(pi(R,D));
		AdjList[R].push_back(pi(L,-D));
	}
	for (int i = 1; i <= N; ++i){
		if (loc[i] == -1e9-1){
			dfs(i,-1);
		}
	}
	if (check == 1) cout << "No\n";
	else cout << "Yes\n";
	cout << flush;
}