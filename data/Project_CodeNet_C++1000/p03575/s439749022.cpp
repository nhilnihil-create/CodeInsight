#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct UnionFind{
    vector<int> data;
    //data[i] = -x ... iが根であり、サイズがx
    //data[i] = x ... iの親がx

    //最初は全員根
    UnionFind(int size): data(size,-1){}

    bool union_set(int x, int y){//サイズがx>yになるようにしてから、xにyをつなげる
        x=root(x);
        y=root(y);
        if(x != y){
            if(data[y] < data[x]) swap(x,y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find_set(int x, int y){//ルートが一致するかどうかを返す
        return root(x) == root(y);
    }
    int root(int x){//根を見つける。ついでに深さ2にしちゃう
        return data[x]<0 ? x : data[x]=root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};

struct Edge{
    int s,t,cost;
    bool operator<(const Edge &o) const{
        return cost < o.cost;
    }
};


int main() {
    int N,M; cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    REP(i,M){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int ans = 0;
    REP(i,M){
        UnionFind uf(N);
        REP(j,M){
            if(i!=j){
                uf.union_set(a[j], b[j]);
            }
        }
        if(!uf.find_set(a[i],b[i])){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}