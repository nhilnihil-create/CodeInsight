#include <bits/stdc++.h>
#define N 100001
#define M 1000000007
using namespace std;
typedef long long lingling;

vector<int> tree[N];
int n;
lingling dp[N][2];

lingling dfs(int node, int parent, bool painted) {
	if (tree[node].size()==0) return 1;
	if (tree[node].size()==1 && tree[node][0]==parent) return 1;
	if (dp[node][painted]!=0) return dp[node][painted];

	lingling res; dp[node][painted]=1;
	for (int i=0; i<tree[node].size(); i++) {
		int child=tree[node][i];
		if (child!=parent) {
			if (painted) res=dfs(child,node,0);
			else res=(dfs(child,node,1)+dfs(child,node,0))%M;
			dp[node][painted]*=res;
			dp[node][painted]%=M;
		}
	}
	return dp[node][painted];
}

int main() {
	cin>>n;
	for (int i=1; i<n; i++) {
		int a, b; cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cout<<(dfs(1,0,0)+dfs(1,0,1))%M<<endl;
}