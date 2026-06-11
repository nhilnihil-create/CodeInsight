#include<bits/stdc++.h> 
#define int long long
using namespace std;
void print (vector<char>&v){
	int k=0;
	for (char i:v) cout<<i<<" ";
	cout<<endl;
}
void printv (vector<vector<char>>&v){
	for (vector<char> i:v) print(i);
	cout<<endl;
}
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	int R,C;
    cin>>R>>C;
    vector<string> graph(R);
    for (int i=0;i<R;i++){
    	cin>>graph[i];	
    }
	cout<< solve(graph,R,C)<<endl;
    return 0; 
}
