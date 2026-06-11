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


// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};


int main(){
	int N, M;
	cin >> N >> M;
	UnionFind uf(N);

	for(int i=0; i<M; i++){
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		uf.unite(x, y);
	}

	int ans = N;
	map<int, int> mp;
	for(int i=0; i<N; i++){
		int root = uf.find(i);
		// cout << "  i: " << i << " root: " << root << " uf.size(root): " << uf.size(root) << endl;
		if(mp[root] != 0) continue;
		mp[root]++;
		int size = uf.size(root);
		ans -= size-1;
	}

	cout << ans << endl;
	return 0;
	}
