#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <fstream>
#include <array>
#include <map>
#include <queue>
#include <time.h>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <assert.h>
#include <unordered_set>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) (min(a,b) <= (x) && (x) <= max(a,b)) //hei
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL 
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589
 
 
#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}
 
//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL
#define chmax(a,b) a = max(a,b)
#define chmin(a,b) a = min(a,b)
 
struct Edge {
	int from, to;
	ll w;
	bool operator<(const Edge& rhs) const {
		return MP(w, MP(from, to)) < MP(rhs.w, MP(rhs.from, rhs.to));
	}
 
};
typedef vector<vector<Edge>> Graph;
typedef unsigned long long ull;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}
ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = (res * x) % MODU;
		x = (x*x)%MODU;
		n >>= 1;
	}
	return res;
}
ll divmod(ll a, ll b) { // a/b(mod m)
								  // a/b (mod m)
								  // a*b^-1
								  // b^-1 * b = 1
								  // b^(m-1) = 1 
								  // b^(m-2) * b = 1
								  // b^-1 = b^(m-2)

								  // a/b = a * b^(m-2)

	return (a * mod_pow(b, MODU - 2)) % MODU;
}
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) { //ｘの入ってる集合と yの入ってる集合を併合
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { //xとyが同じ集合に入っているかどうかを判定
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool isroot(int x) {
		return data[x] < 0;
	}
	int size(int x) {
		return -data[root(x)];
	}
};


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n){
		cin >> a[i];
	}
	map<long long int,int> cnt;
	long long int acc = 0, ans = 0;

	REP(i,n){
		cnt[acc]++;
		acc += a[i];
		ans += cnt[acc];
	}

	cout << ans << endl;

	return 0;
}   