#include<iostream>
#include<vector>

using namespace std;

struct Union_find{
	vector<int> par;
	vector<int> rank;
	vector<int> diff_weight;
	Union_find(int p){
		par = vector<int>(p + 1);
		rank = vector<int>(p + 1);
		diff_weight = vector<int>(p + 1);
		for(int i = 1; i <= p; i++){
			par[i] = i;
		}
	}
	int find(int x){
		if(par[x] == x)
			return x;
		else{
			int pa = find(par[x]);
			diff_weight[x] += diff_weight[par[x]];
			return par[x] = pa;
		}
	}
	bool unite(int x, int y, int w){
		w = w + weight(x) - weight(y);
		x = find(x);
		y = find(y);
		if(x == y) return false;
		if(rank[x] < rank[y]){
			par[x] = y;
			diff_weight[x] = - 1 * w;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
			diff_weight[y] = w;
		}
		return true;
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
	int weight(int x){
		find(x);
		return diff_weight[x];
	}
	int diff(int x, int y){
		return weight(y) - weight(x);
	}
};

int main(){
	int n, m, ans = 0;
	cin >> n >> m;
	if(m == 0){
		cout << "Yes" << endl;
		return 0;
	}
	Union_find uf(n);
	for(int i = 0; i < m; i++){
		int x, y, c;
		cin >> x >> y >> c;
		if(uf.unite(x, y, c)){
			continue;
		}else{
			if(uf.diff(x, y) != c){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}