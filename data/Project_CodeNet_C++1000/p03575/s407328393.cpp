#include <bits/stdc++.h>
using namespace std;
template <class T> T input() {T t; cin>>t; return t;}
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define CHMAX(a,b) a = max(a,b)
#define CHMIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define newline putchar('\n')
#define cspace ' '
#define sspace " "
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;
const VI dx = {1, 0, -1, 0};
const VI dy = {0, 1, 0, -1};

class UnionFindTree {
public:
    int size;
    vector<int> rank, p;

    UnionFindTree() {}

    UnionFindTree(int num) {
        size = num;
        rank.resize(size, 0);
        p.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            makeSet(i);
        }
    }

    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y)
    {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y)
    {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y)
    {
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int findSet(int x)
    {
        if (x != p[x]) {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    int maxUnion()
    {
        int r = 0;
        map<int, int> mp;
        REP(i,size) {
            mp[findSet(i)]++;
        }
        REPITR(itr,mp) {
            r = CHMAX(r, itr->e2);
        }
        return r;
    }
};

int main()
{
    int n, m, ans = 0;
    cin>>n>>m;
    VI a(m), b(m);
    REP(i,m) cin>>a[i]>>b[i];
    REP(i,m) {
        UnionFindTree uf(n);
        REP(j,m) {
            if (i != j) {
                uf.unite(a[j]-1, b[j]-1);
            }
        }
        if (uf.maxUnion() != n) {
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
