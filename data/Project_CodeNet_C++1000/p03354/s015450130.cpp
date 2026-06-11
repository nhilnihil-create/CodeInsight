#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

struct UnionFind
{
    std::vector<int> par; // parent node
    std::vector<int> rank; // tree height
    
    UnionFind(int n=1) // constructor
    {
        init(n);
    }

    void init(int n=1) // initialize
    {
        par.resize(n);rank.resize(n);
        // All vertices are root and height of 0 in the beginning.
        for(int i=0; i<n; ++i) par[i]=i, rank[i]=0; 
    }

    int root(int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        else
        {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool isSame(int x, int y) // judging of whether x and y belong to same group.
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y) // merge the group to which x belongs and the group to which group y belongs. 
    {                        // merge the group of y into the group of x. x <--- y
        x = root(x); y= root(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x,y);
        if(rank[x]==rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    UnionFind utree = UnionFind(n);
    int p[n]; bool is[n];
    for (int i=0; i<n; ++i)
    {
        int tmp;
        cin >> tmp; 
        p[i] = tmp - 1;
        if(i==p[i]) is[i] = true;
        else is[i] = false;
    }

    for (int i=0; i<m; ++i)
    {
        int x,y;
        cin >> x >> y;
        // cout << x << y << endl;
        utree.merge(x-1,y-1); 
    }

    int cnt = 0;
    for (int i=0; i<n; ++i)
    {
        if(!is[i])
        {
            if(utree.root(i) != utree.root(p[i])) ++cnt;
            // if(utree.par[i] != utree.par[p[i]]) ++cnt;
        }
    }

    cout << n - cnt << endl;

    return 0;
}