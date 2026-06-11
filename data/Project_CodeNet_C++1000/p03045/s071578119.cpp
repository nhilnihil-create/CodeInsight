#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
struct UnionFind{
    vector<int> parent;
    vector<int> rank; // tree's depth
 
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n);
        init(n);
    }
 
    // initialize
    void init(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    // find root
    int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            return parent[x] = find(parent[x]);
        }
    }
 
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
 
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
 
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    int n, m; cin >> n >> m;
    UnionFind UF(n);

    int x, y, z;
    rep(i, m){
        cin >> x >> y >> z;
        x--, y--;
        UF.unite(x, y);
    }
    set<int> count;
    rep(i, n) count.insert(UF.find(i));
    cout << count.size() << endl;
}