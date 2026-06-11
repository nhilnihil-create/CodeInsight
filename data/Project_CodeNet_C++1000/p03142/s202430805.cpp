#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(0));
	vector<vector<int>> gr(n, vector<int>(0));
	vector<int> in(n);
	vector<int> ans(n);
	rep(i, n-1+m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		gr[b].push_back(a);
		in[b]++;
	}
	int o = 0;
	rep(i, n) if(in[i] == 0) o = i;
	queue<int> q;
	q.push(o);
	ans[o] = 0;
	int cou = 0;
	while(!q.empty()){
		int x = q.front();
		rep(i, g[x].size()){
			int xn = g[x][i];
			in[xn]--;
			if(in[xn] == 0){
				q.push(xn);
				cou++;
				ans[xn] = cou;
			}
		}
		q.pop();
	}
	rep(i, n){
		int ma = -1;
		int oy = 0;
		rep(j, gr[i].size()) if(ma < ans[gr[i][j]]){ ma = ans[gr[i][j]]; oy = gr[i][j];}
		if(ma != -1){
			cout << oy+1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
}