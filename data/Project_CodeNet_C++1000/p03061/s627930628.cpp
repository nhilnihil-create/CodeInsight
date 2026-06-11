#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T>
class SegTree{

private:

	int n;
	int m;
	int depth;
	T def;
	vector<T> data;
	function<T(T,T)> calculate;
	function<T(T,T)> update;

	T rec(int l, int r, int node, int node_l, int node_r) {
		if (node_r <= l || node_l >= r) return def;
		if (node_l >= l && node_r <= r) return data[node];
		int mid = (node_l + node_r) / 2;
		return calculate(
			rec(l, r, node * 2, node_l, mid),
			rec(l, r, node * 2 + 1, mid, node_r));
	}



public:


	SegTree(vector<T> a, T _def, function<T(T,T)> _calculate, function<T(T,T)> _update):
	def(_def), calculate(_calculate), update(_update) {
		m = a.size();
		for (n = 1; n < (int) a.size(); n *= 2, depth++);
		data.resize(n * 2, def);
		for (int i = 0; i < (int) a.size(); i++) data[i + n] = a[i];
		for (int i = n - 1; i >= 1; i--)
			data[i] = calculate(data[i * 2], data[i * 2 + 1]);
	}


	//区間取得
	T get(int l,int r){
		if(l == r)return def;
		return rec(l,r,1,0,n);
	}

	//一点更新
	void assign(int index, T val){
		index += n;
		data[index] = update(data[index], val);
		for(;index /= 2;)
			data[index] = calculate(data[index * 2],data[index * 2 + 1]);
	}


	void print() {
		cerr << "[";
		for(int i = 0; i < m; i++) {
			cerr << data[i + n] << (i != m - 1 ? "," : "]\n");
		}
	}

	T operator[] (int i){
		return data[i + n];
	}

};

/*
Constructor: O(N) 初期配列, 単位元, 演算, 更新
	演算: (v1, v2) -> calc(v1, v2)
	更新: (index, value) -> SegTree[index] := value
get(left, right): O(logN) [left, right)での区間和
assign(index, value): O(logN) 一点更新
opertor[index]: O(1)
*/


int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	SegTree<int> tree(a, 0, [](int a, int b){return __gcd(a, b);}, [](int a, int b){return b;});
	int nax = 0;
	for(int i = 0; i < n; i++) {
		tree.assign(i, 0);
		nax = max(nax, tree.get(0, n));
		tree.assign(i, a[i]);
	}
	cout << nax << endl;
}
