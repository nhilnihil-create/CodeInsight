#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class M> class SegmentTree {
public:
	using T = typename M::value_type;
private:
	int m;
	int n;
	vector<T> data;

	T rec(int l, int r, int node, int node_l, int node_r) {
		if(node_r <= l || node_l >= r)return M::id;
		if(node_l >= l && node_r <= r)return data[node];
		int mid = (node_l + node_r) / 2;
		return M::op(
			rec(l, r, node * 2, node_l, mid),
			rec(l, r, node * 2 + 1, mid, node_r)
		);
	}

public:
	SegmentTree(const vector<T>& a) {
		m = a.size();
		for(n = 1; n < (int)a.size(); n <<= 1);
		data.resize(n<<1, M::id);
		for(int i = 0; i < (int)a.size(); i++)data[i + n] = a[i];
		for(int i = n - 1; i >= 1; i--) data[i] = M::op(data[i<<1], data[(i<<1) + 1]);
	}
 
	T get(int l, int r) {
		return rec(l, r, 1, 0, n);
	}
 
	void assign(int index, T val) {
		index += n;
		data[index] = val;
		while(index != 1){
			index >>= 1;
			data[index] = M::op(data[index<<1], data[(index<<1) + 1]);
		}
	}
 
	T operator[] (int i){
		return data[i + n];
	}
 
};
 
template<class T> class Gcd {
public:
    using value_type = T;
    static T op(T l, T r) {return __gcd(l, r);}
    static constexpr T id = 0;
};
 
int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	SegmentTree<Gcd<int>> tree(a);
	int nax = 0;
	for(int i = 0; i < n; i++) {
		tree.assign(i, 0);
		nax = max(nax, tree.get(0, n));
		tree.assign(i, a[i]);
	}
	cout << nax << endl;
}