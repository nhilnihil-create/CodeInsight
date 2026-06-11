#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    int rootNum;

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        rootNum = N;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int getRootNum() {
        return rootNum;
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        rootNum--;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind un(N);
    rep(i, M) {
        int x, y, z;
        cin >> x >> y >> z;
        un.unite(x-1, y-1);
    }

    cout << un.getRootNum() << endl;
}