#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
       for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
       if (par[x] == x) return x;
       return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
       int rx = root(x); //xの根をrx
       int ry = root(y); //yの根をry
       if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
       par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
       int rx = root(x);
       int ry = root(y);
       return rx == ry;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    vint a(m), b(m), c(n, 1);
    rep(i, m) {
        cin >> a[i];
        cin >> b[i];
        a[i]--; b[i]--;
    }

    vll ans;
    ans.push_back((ll)n*(n-1)/2);

    for(int i=m-1; i>0; i--){
        // prvec(c);
        if(uf.same(a[i], b[i])){
            ans.push_back(ans.back());
            continue;
        }
        int ap=uf.par[a[i]], bp=uf.par[b[i]];
        uf.unite(a[i], b[i]);
        ll t;
        t = ans.back() - (ll)c[ap]*c[bp];
        ans.push_back(t);

        c[ap] += c[bp];
        c[bp] = c[ap];
        c[a[i]] = c[ap];
        c[b[i]] = c[ap];
        // c[uf.par[b[i]]] += ap;
    }

    reverse(ALL(ans));
    rep(i, m) pr(ans[i]);
    return 0;}