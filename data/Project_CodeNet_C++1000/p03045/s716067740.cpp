#include <bits/stdc++.h>
using namespace std;
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
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;

class UnionFindTree {
public:
    vector<int> rank, p;

    UnionFindTree() {}

    UnionFindTree(int size) {
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
        int size = p.size();
        int r = 0;
        REP(i,size) {
            r = max(r, (int)count(p.begin(), p.end(), i));
        }
        return r;
    }
};

int main()
{
    int n, m;
    cin>>n>>m;
    UnionFindTree uf(n);
    REP(i,m) {
        int x, y, z;
        cin>>x>>y>>z;
        uf.unite(x-1, y-1);
    }

    int cnt = 0;
    set<int> p_set;
    REP(i,n) {
        if (p_set.find(uf.findSet(i)) == p_set.end()) {
            p_set.insert(uf.findSet(i));
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
