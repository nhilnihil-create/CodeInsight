#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<cstdint>
#include<chrono>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define veccat(v1, v2) std::copy((v2).begin(),(v2).end(),std::back_inserter(v1)/*v1の後ろにv2を入れる*/)
#define intmax (std::numeric_limits<int64_t>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;


class segtree_min_pointupdate {
private:
	typedef int T;
public:
	segtree_min_pointupdate(const int N) {
		SIZE = roundup_pow2(N);
		v.clear();
		v.resize(SIZE * 2, numeric_limits<T>::max());
	}

	//v[index]=numberとする。
	void update(const int index, const T number) {
		v[index + SIZE] = number;
		for (int i = (index + SIZE) / 2; i; i = i / 2)v[i] = min(v[i * 2], v[i * 2 + 1]);
	}

	//[index]の値を返す。
	T getnum(const int index) {
		return v[index + SIZE];
	}

	//[L,R)の最小値を返す。
	T getmin(const int L, const int R) {
		return getmin_inner(L, R, 1, 0, SIZE);
	}
private:
	T getmin_inner(const int queryL, const int queryR, const int index, const int segL, const int segR) {
		if (queryR <= segL || segR <= queryL)return numeric_limits<T>::max();
		if (queryL <= segL && segR <= queryR)return v[index];
		return min(getmin_inner(queryL, queryR, index * 2, segL, (segL + segR) / 2),
			getmin_inner(queryL, queryR, index * 2 + 1, (segL + segR) / 2, segR));
	}

	//x以上であるような2のべき乗数のうち最小のものを返す。
	int roundup_pow2(int x) {
		x--;
		rep(i, 6)x |= x >> (1LL << i);
		return x + 1;
	}

	int SIZE;
	vector<T>v;
};
class segtree_max_pointupdate {
private:
	typedef int T;
public:
	segtree_max_pointupdate(const int N) {
		SIZE = roundup_pow2(N);
		v.clear();
		v.resize(SIZE * 2, numeric_limits<int>::min());
	}

	//v[index]=numberとする。
	void update(const int index, const T number) {
		v[index + SIZE] = number;
		for (int i = (index + SIZE) / 2; i; i = i / 2)v[i] = max(v[i * 2], v[i * 2 + 1]);
	}

	//[index]の値を返す。
	T getnum(const int index) {
		return v[index + SIZE];
	}

	//[L,R)の最大値を返す。
	T getmax(const int L, const int R) {
		return getmax_inner(L, R, 1, 0, SIZE);
	}
private:
	T getmax_inner(const int queryL, const int queryR, const int index, const int segL, const int segR) {
		if (queryR <= segL || segR <= queryL)return numeric_limits<int>::min();
		if (queryL <= segL && segR <= queryR)return v[index];
		return max(getmax_inner(queryL, queryR, index * 2, segL, (segL + segR) / 2),
			getmax_inner(queryL, queryR, index * 2 + 1, (segL + segR) / 2, segR));
	}

	//x以上であるような2のべき乗数のうち最小のものを返す。
	int roundup_pow2(int x) {
		x--;
		rep(i, 6)x |= x >> (1LL << i);
		return x + 1;
	}

	int SIZE;
	vector<T>v;
};
class union_find {
public:
	union_find(const int N) :v(N), size(N) {
		tree_num = N;
		rep(i, N)v[i] = i;
		rep(i, N)size[i] = 1;
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b)return;

		if (size[a] < size[b])swap(a, b);
		v[b] = a;
		size[a] += size[b];
		tree_num--;
	}

	bool same(int a, int b) { return find(a) == find(b); }

	int get_size(int a) {
		return size[find(a)];
	}
	int get_tree_num() { return tree_num; }

private:
	vector<int> v;
	vector<int> size;
	int tree_num;

	int find(int a) {
		if (v[a] == a)return a;
		return v[a] = find(v[a]);
	}
};


signed main() {

	int M, K;
	cin >> M >> K;

	if ((1LL << M) <= K) {
		cout << -1 << endl;
		return 0;
	}

	if (M == 0) {
		cout << "0 0" << endl;
		return 0;
	}
	if (M == 1) {
		if (K == 0) {
			cout << "0 0 1 1" << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < (1LL << M); ++i)if (i != K)cout << i << " ";
	cout << K << " ";
	for (int i = (1LL << M) - 1; i >= 0; --i)if (i != K)cout << i << " ";
	cout << K << endl;

	return 0;
}