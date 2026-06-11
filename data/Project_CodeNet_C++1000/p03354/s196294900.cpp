#include <bits/stdc++.h>
using namespace std;

// 型名の省略
typedef unsigned int uint;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> P;
typedef pair<lint, lint> Plint;
 
const int MOD = 1e9+7;
const int INF = 1<<18;
const lint INFLINT = 1LL<<60;
const double PI=acos(-1.0);
 
// cinとcoutの高速化
#define endl "\n"
struct cinacc{cinacc(){cin.tie(0);ios::sync_with_stdio(false);}}cinaccc;
struct coutacc{coutacc(){cout.setf(ios::fixed);cout.precision(12);}}coutaccc;
 
// 繰り返し
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#define reps(i,n) for(lint i=0;i<=(lint)(n);i++)
#define rrep(i,n) for(lint i=(lint)(n)-1;i>0;i--)
#define rreps(i,n) for(lint i=(lint)(n)-1;i>=0;i--)

#define pb push_back

#define ALL(s) (s.begin(), s.end())
#define SZ(s) (s.size())

template<class T>bool chmax(T&a,const T&b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a,const T&b){if(b<a){a=b;return true;}return false;}

// Union-Find-Tree
struct UnionFind {
	vector<int> par;
	UnionFind(int n):par(n){rep(i,n)par[i]=i;}
	int root(int x){if(par[x]==x)return x;return par[x]=root(par[x]);}
	void unite(int x,int y){int rx=root(x);int ry=root(y);if(rx==ry)return;par[rx]=ry;}
	bool same(int x,int y){return root(x)==root(y);}
};

// Final Weapon!
// #define int lint

int main() {
    int n, m, x, y, tmp;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> tmp;
        p[i] = tmp - 1;
    }
    
    UnionFind uf(n);
    
    rep(i, m) {
        cin >> x >> y;
        uf.unite(x - 1, y - 1);
    }
    
    int count = 0;
    rep(i, n) {
        if(uf.same(i, p[i])) count++;
    }
    cout << count << endl;
    
    return 0;
}
