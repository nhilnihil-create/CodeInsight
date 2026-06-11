#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

struct UnionFind{
    vector<int> branch;
    UnionFind(int N = 0) : branch(N,-1){}

    int find(int x){
        if(branch[x] < 0) return x;
        else return branch[x] = find(branch[x]);//メモ化、要素を入れて根が返ってくる
    }

    bool unite(int x, int y){
        int rx,ry;
        rx = find(x);
        ry = find(y);
        if(rx == ry) return false;//連結できたかどうか
        if(-branch[rx] < -branch[ry]) swap(rx,ry);
        branch[rx] += branch[ry];//木のサイズを負の値で管理
        branch[ry] = rx;
        return true;
    }

    bool same(int x, int y){
        if(find(x) == find(y)) return true;
        else return false;
    }

    int size(int x){
        return -branch[find(x)];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind il(n);
    vector<pair<int,int>> bg(m);
    vector<ll> can;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        bg[i] = {a,b};
    } 
    reverse(bg.begin(),bg.end());
    for(int i = 0; i < m; i++){
        if(il.same(bg[i].first,bg[i].second)) can.push_back(0);
        else can.push_back(il.size(bg[i].first)*il.size(bg[i].second));
        il.unite(bg[i].first,bg[i].second);
    }
    reverse(can.begin(),can.end());
    ll now = 0;
    for(int i = 0; i < m; i++){
        now += can[i];
        cout << now << endl;
    }
    return 0;
}