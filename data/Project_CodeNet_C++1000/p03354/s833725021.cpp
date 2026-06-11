#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
struct UnionFind{
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n):parent(n),rank(n){
        for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int root(int x){
        if (parent[x]==x)return x;
        return parent[x]=root(parent[x]);
    }
    void unite(int x, int y){
        int rx=root(x);
        int ry=root(y);
        if (rx==ry)return;
        if (rank[rx]<rank[ry]) parent[rx]=ry;
        else{
            parent[ry]=rx;
            if (rank[rx]==rank[ry]) rank[rx]++;
        }
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<int> p(n);
    for (int i = 0;i<n;i++)
        cin >> p[i];
    unordered_map<int,int> D;
    for (int i = 0; i < n;i++){
        D[p[i]-1] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x, y);
    }
    int res=0;
    for(auto it:D){
        if(uf.same(it.first,it.second)){
            res++;
        }
    }
    cout << res << endl;


}