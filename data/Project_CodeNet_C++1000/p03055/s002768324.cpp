#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433L;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

template<class Operator> class Tree {
	Operator Op;                            
	using typeDist = decltype(Op.unitDist); 
	using typeLca = decltype(Op.unitLca); 
	size_t num;
	size_t ord;
public:
	vector<vector<pair<size_t,typeDist>>> edge;
	vector<size_t> depth;
	vector<size_t> order;
	vector<typeDist> dist;
	vector<pair<size_t,typeDist>> parent;
	vector<vector<pair<size_t,typeDist>>> child;
	vector<array<pair<size_t,typeLca>,Operator::bit>> ancestor;
	vector<size_t> size;
	Tree(const int num):num(num),edge(num),depth(num),order(num),dist(num){}
	//O(1) anytime
	void makeEdge(const int& from, const int& to, const typeDist w = 1) {
		edge[from].push_back({to,w});
	}
	//O(N) anytime
	void makeDepth(const int root) {
		depth[root] = 0;
		dist[root] = Op.unitDist;
		ord = 0;
		dfs1(root);
		order[ord++] = root;
	}
	//for makeDepth
	void dfs1(int curr, int prev = -1){
		for(auto& e:edge[curr]){
			int next = e.first;
			if(next==prev) continue;
			depth[next] = depth[curr] + 1;
			dist[next]  = Op.funcDist(dist[curr],e.second);
			dfs1(next,curr);
			order[ord++] = next;
		}
	}
	//O(N) after makeDepth
	void makeParent(void) {
		parent.resize(num);
		for (int i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] > depth[e.first]) parent[i] = e;
	}
	//O(N) after makeDepth
	void makeChild(void) {
		child.resize(num);
		for (int i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);
	}
	//O(NlogN) after makeDepth and makeParent
	void makeAncestor(void) {
		ancestor.resize(num);
		for (int i = 0; i < num; ++i) ancestor[i][0] = parent[i];
		ancestor[order.back()][0] = make_pair(order.back(),Op.unitLca);
		for (int j = 1; j < Operator::bit; ++j) {
			for (int i = 0; i < num; ++i) {
				size_t k = ancestor[i][j - 1].first;
				ancestor[i][j] = Op.funcLca(ancestor[k][j - 1],ancestor[i][j - 1]);
			}
		}
	}
	//O(logN) after makeAncestor
	pair<size_t,typeLca> lca(size_t l, size_t r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		auto ancl = make_pair(l,Op.unitLca);
		auto ancr = make_pair(r,Op.unitLca);
		for (int j = 0; j < Operator::bit; ++j) {
			if (diff & (1 << j)) {
				ancl = Op.funcLca(ancestor[ancl.first][j],ancl);
			}
		}
		if(ancl.first==ancr.first) return ancl;
		for (int j = Operator::bit - 1; 0 <= j; --j) {
			if(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first) {
				ancl = Op.funcLca(ancestor[ancl.first][j],ancl);
				ancr = Op.funcLca(ancestor[ancr.first][j],ancr);
			}
		}
		ancl = Op.funcLca(ancestor[ancl.first][0],ancl);
		ancr = Op.funcLca(ancestor[ancr.first][0],ancr);
		return Op.funcLca(ancl,ancr);
	}
	//O(N) anytime
	int diameter(void){
		makeDepth(0);
		int tmp = max_element(depth.begin(), depth.end()) - depth.begin();
		makeDepth(tmp);
		return *max_element(depth.begin(), depth.end());
	}
};
template<class typeDist,class typeLca = typeDist> struct treeOperator{
	static const size_t bit = 20;
	typeDist unitDist = 0;
	typeDist unitLca = 0;
	typeDist funcDist(const typeDist& parent,const typeDist& w){return parent+w;}
	pair<size_t,typeDist> funcLca(const pair<size_t,typeDist>& l,const pair<size_t,typeDist>& r){return make_pair(l.first,l.second+r.second);}
};
 
//depth,dist
//https://atcoder.jp/contests/abc126/tasks/abc126_d
 
//lca
//https://atcoder.jp/contests/abc014/tasks/abc014_4
 
//child
//https://atcoder.jp/contests/abc133/tasks/abc133_e

//diameter
//https://atcoder.jp/contests/agc033/tasks/agc033_c

//eulerTour
//https://yukicoder.me/problems/no/900

// Tree<treeOperator<int>> tree(N);

int main() {
	int N; cin >> N;
	if(N==1){
		cout << "First" << endl;
		return 0;
	};
	Tree<treeOperator<int>> tree(N);
	for(int i = 0; i < N-1; ++i){
		int u,v; cin >> u >> v;
		u--,v--;
		tree.makeEdge(u,v);
		tree.makeEdge(v,u);
	}
	cout << (tree.diameter()%3==1?"Second":"First") << endl;
     return 0;
}
