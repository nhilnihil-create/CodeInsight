#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
 
    // 集合をマージする
    // すでに同じ集合ならfalseが返る
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (data[y] < data[x]) swap(x, y);  // マージテク
        data[x] += data[y];
        data[y] = x;
        return true;
    }
 
    // ある要素がどの集合に属しているかを答える
    int root(int x) {
        // 根に直接つなぎ直す
        return data[x]<0 ? x : (data[x]=root(data[x]));
    }
 
    // ある集合の大きさを答える
    int size(int x) {
        return -data[root(x)];
    }
};

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll>p(n),x(m),y(m);
    UnionFind uf(n);
    ll answer = 0;
    REP(i,n){
        cin >> p[i];
        p[i]--;
    }
    REP(i,m){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    REP(i,m){
        uf.merge(x[i],y[i]);
    }
    REP(i,n){
        if(uf.root(p[i])==uf.root(i)){
            answer++;
        }
        else{
            //cout << uf.root(p[i]) << " debug " << uf.root(i)<< endl;
        }
    }
    cout << answer << endl;
    return 0;
}