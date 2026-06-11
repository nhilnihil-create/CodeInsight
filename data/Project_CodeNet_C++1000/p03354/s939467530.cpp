#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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

struct UnionFind{
	////https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
	
	//parent[i]: iの親の番号
	//例: parent[3] = 2: 3の親は2
	vector<int> parent;

	UnionFind(int N) : parent(N){
		//初期化は自分自身が親とする
		for(int i=0; i<N; i++) parent[i] = i;
	}

	int root(int x){
		if(parent[x] == x) return x;
		return parent[x] = root(parent[x]);
	}

	void unite(int x, int y){
		int rx = root(x);
		int ry = root(y);
		if(rx == ry) return;
		parent[rx] = ry;//rxの親をryの親にする
	}
	bool same(int x, int y){ return root(x) == root(y);}
};

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> p(N);
	for(int i=0; i<N; i++) cin >> p[i];
	for(int i=0; i<N; i++) p[i]--;
	UnionFind tree(N);
	for(int i=0; i<M; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		tree.unite(x, y);
	}

	int ans = 0;
	for(int i=0; i<N; i++){
		if(tree.same(i, p[i])) ans++;
		else if(p[i] == i) ans++;
		// cout << " i: " << i << " p[" << i << "]: " << p[i] << " ans: " << ans << endl;
	}
	cout << ans << endl;

	return 0;
}

