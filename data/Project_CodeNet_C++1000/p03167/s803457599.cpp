#include<bits/stdc++.h> 
using namespace std;
int mod=1e9+7;
int solve(vector<string>& graph, int R, int C){
	vector<vector<int>> ans(R,vector<int>(C,0));
	for (int i=0;i<R;i++){
		if (graph[i][0]=='#') break;
		else ans[i][0]=1;
	}
	for (int i=0;i<C;i++){
		if (graph[0][i]=='#') break;
		else ans[0][i]=1;
	}
	for (int i=1;i<R;i++){
		for (int j=1;j<C;j++){
			if (graph[i][j]!='#'){
				ans[i][j]=(ans[i-1][j]%mod+ans[i][j-1]%mod)%mod;
			}
		}
	}
	return ans[R-1][C-1];
}
signed main() {
	int R,C;
    cin>>R>>C;
    vector<string> graph(R);
    for (int i=0;i<R;i++){
    	cin>>graph[i];	
    }
	cout<< solve(graph,R,C)<<endl;
    return 0; 
}
