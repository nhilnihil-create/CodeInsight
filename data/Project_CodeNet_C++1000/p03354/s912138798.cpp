#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#include<iostream>

int const MAX_N = 100000;
int par[MAX_N]; // 親
int depth[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        depth[i] = 0;
    }
}

// 木の根を求める
int find(int x){
    if (par[x] == x) {
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を合併
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (depth[x] < depth[y]) {
        par[x] = y;
    }else{
        par[y] = x;
        if (depth[x] == depth[y]) depth[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}


int main(){
    int n, m;
    cin >> n >> m;
    int p[n];
    rep(i, n){cin >> p[i]; p[i]--;}
    init(n);
    int x, y;
    rep(i, m) {
        cin >> x >> y;
        x--; y--;
        unite(x, y);
    }
    int ans = 0;
    rep(i, n){
        if (i != p[i]){
            if (same(i, p[i])){
                ans++;
            }
        }else{
            ans++;
        }
    }
    cout << ans << endl;
}