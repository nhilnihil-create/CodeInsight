#include <bits/stdc++.h>
using namespace std;

int n, m;

class WeightedUnionFind{
	public:
		vector<int> Parent;
		vector<int> Rank;
		vector<long long> Weight;
		WeightedUnionFind(int n){
			++n;
			Parent.resize(n, 0);
			Rank.resize(n, 0);
			Weight.resize(n, 0);
			for(int i=0; i<n; ++i)
				Parent[i] = i;
		}

		int find(int x){
			if(Parent[x] == x) return x;
			int pastparent = Parent[x];
			Parent[x] = find(Parent[x]);
			Weight[x] += Weight[pastparent];
			return Parent[x];
		}

		bool unite(int x, int y, long long z){ // a[y] - a[x] == z
			int sx = x, sy = y;
			x = find(x);
			y = find(y);
			if(x == y) return false;
			if(Rank[x] < Rank[y]){
				Parent[x] = y;
				Weight[x] = z + Weight[sy] - Weight[sx];
			}else{
				Parent[y] = x;
				Weight[y] = - z - Weight[sy] + Weight[sx];
				if(Rank[x] == Rank[y]) ++Rank[x];
			}
			return true;
		}

		bool same(int x, int y){
			return find(x) == find(y);
		}

		long long cost(int x, int y){ // call only if same(x, y) == true
			return Weight[x] - Weight[y];
		}
};

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> m;
	WeightedUnionFind wuf(n);
	for(int i=0; i<m; ++i){
		int l, r, d;
		cin >> l >> r >> d;
		if(wuf.same(l, r) && wuf.cost(l, r) != d){
			cout << "No\n";
			return 0;
		}
		wuf.unite(l, r, d);
	}
	cout << "Yes\n";
}