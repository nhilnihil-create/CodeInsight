#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

template<typename T>
void print1(T begin, T end) {
	while (begin != end) {
		cerr << (*begin) << " ";
		*begin++;
	}
	cerr << endl;
}

template<typename T>
void print2(T Array, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cerr << " " << Array[i][j];
		}
		cerr << endl;
	}
}

void print() { std::cerr << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
	std::cerr << head << " ";
	print(std::forward<Tail>(tail)...);
}

template<class T>
void Add(T &a, const T &b, const T &mod=1000000007) {
	int val = ((a % mod) + (b % mod)) % mod;
	if (val < 0) { val += mod; }
	a = val;
}

template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

// ------------------------------------------------------------------------------------------

int N;
const int maxV = 222222;
vector<int> G[maxV]; // 頂点情報のみのグラフ

// treeDFS(親, 現在地, 根から現在地までの距離, 根からの最大の距離, 根から最大の距離となる頂点
void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex) {
    // 距離と終点を更新
    if (dist > maxDist) {
        maxDist = dist;
        maxVertex = current;
    }

    for (auto to : G[current]) {
        // 逆流を防ぐ
        if (to == from) continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex);
    }
}

int getTreeDiameter() {
    int start = 0, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    start = end, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
		return maxDist;
}

signed main() {
	cin >> N;
	rep (i, N-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int dia = getTreeDiameter();
	// int dia;
	// cin >> dia;
	
	dbg(dia)
	puts(dia % 3 == 1 ? "Second" : "First");


	return 0;
}
