#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

struct UnionFind{
    vector<int> rank,p;
    UnionFind(int size){
        rank.resize(size,0);
        p.resize(size,0);
        for(int i = 0; i < size; i++){
            p[i] = i;
            rank[i] = 0;
        }
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int root(int x){
        if(x != p[x]){
            p[x] = root(p[x]);
        }
        return p[x];
    }
    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(rank[rx] > rank[ry]){
            p[ry] = rx;
        }else{
            p[rx] = ry;
            if(rank[rx] == rank[ry]){
                rank[ry]++;
            }
        }
    }
};


int main()
{
    int n,m;
    cin >> n >> m;

    UnionFind uf(n);

    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x,y);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(uf.same(i,p[i])){
            ans++;
        }
    }
    cout << ans << endl;
}