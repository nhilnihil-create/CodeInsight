#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

template<typename T> //最大公約数
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T> //最小公倍数
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

struct Edge
{
    int to, cost;
};
struct Node
{
    int from, to, cost;
};

bool comp(const Node& n1, const Node& n2){
    return n1.cost < n2.cost;
}

struct UnionFind {
	vector<int> par, rank, cnt;
	UnionFind(int n) : par(n), rank(n, 0), cnt(n, 1){
		for(int i = 0; i < n; ++i) par[i] = i;
	}
 
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
 
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
 
		if (rank[x] < rank[y]) swap(x, y);
 
		par[y] = x;
		cnt[x] += cnt[y];
		if (rank[x] == rank[y]) rank[x]++;
	}
 
	bool same(int x, int y) {
		return find(x) == find(y);
	}
 
	int size(int x) {
		return cnt[find(x)];
	}
};



int main(){
    int N, M; cin >> N >> M;
    UnionFind uf(N);
    vector<int> p(N);
    for (int i = 0; i < N; i++){
        cin >> p[i]; p[i]--;
    }
    for (int i = 0; i < M; i++){
        int x, y; cin >> x >> y; x--; y--;
        uf.unite(p[x], p[y]);
    }
    int ans = 0;
    for (int i = 0; i < N; i++){
        if (uf.same(i, p[i])){
            ans++;
        }
    }
    cout << ans << endl;
}