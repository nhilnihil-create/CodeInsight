#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}


using P = pair<int, int>;
int main(){
	int N;
	cin >> N;

	vector<vector<P>> vec(N);
	for(int i=0; i<N-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		vec[u].emplace_back(v, w);
		vec[v].emplace_back(u, w);
	}

	// DFS
	vector<int> color(N, -1);
	stack<P> st;
	st.push(P(0, -1));
	color[0] = 0;//最初の1個を適当に塗る
	while(!st.empty()){
		int node = st.top().first;
		int parent = st.top().second;
		st.pop();

		for(P x : vec[node]){
			// cout << "  node: " << node+1 << " parent: " << parent + 1 << "  child: " << child + 1 << endl;
			int child = x.first;
			int w = x.second;
			if(child == parent) continue;
			if(color[child] != -1) continue;
			if(w % 2 == 1) color[child] = (color[node] + 1) % 2;
			else color[child] = color[node];
			st.push(P(child, node));
		}
	}
	
	for(int i=0; i<N; i++) cout << color[i] << endl;
	return 0;
}
