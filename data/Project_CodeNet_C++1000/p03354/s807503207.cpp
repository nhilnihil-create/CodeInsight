#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};


const int MAX = 510000;
const int MOD = 1000000007;

class UnionFind {
public:
    std::vector<int> RANK;
    std::vector<int> par;

public:
    UnionFind(int n)
    {
        RANK.resize(n);
        par.resize(n);
        for(int i = 0; i < n; ++i) par[i] = i;
    }

    int FindRoot(int x)
    {
        if (par[x] == x) return x;
        par[x] = FindRoot(par[x]);
        return par[x];
    }

    bool IsSame(int x, int y)
    {
        return FindRoot(x) == FindRoot(y);
    }

    void Union(int x, int y)
    {
        x = FindRoot(x);
        y = FindRoot(y);
        if (x == y) return;
        else{
            if(RANK[x] > RANK[y]){
                par[y] = x;
            }
            else{
                par[x] = y;
                if(RANK[x] == RANK[y]){
                    RANK[x]++;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n,m; cin >> n >> m;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    UnionFind uf(n);
    while(m--)
    {
        int x, y; cin >> x >> y;
        x--; y--;
        uf.Union(x,y);
    }

    int ans = 0;
    rep(i,n)
    {
        if(i+1 == p[i])
        {
            ans++;
            continue;
        }
        if(uf.IsSame(i,p[i]-1)) ans++;
    }

    cout << ans << endl;
    return 0;
}