#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;


//unionfind
//init: union_find name(size)

class union_find{
private:
    //根にはグループの要素数に-1をかけたもの、それ以外には根の値
    //初期値は-1
    vector<int> uni;
public:
    //Constructer
    //uniを必要なサイズで初期化する、初期値は―1
    union_find(int unisize) : uni(unisize,-1){}

    //引数aの根を求める、なければaを根として返す
    int root(int a){
        if(uni[a] < 0) return a;
        return uni[a] = root(uni[a]);  
    }

    //頂点aとbを繋ぐ関数unite
    //戻り値：
    //  元々同じグループであればfalse
    //  連結に成功すればtrue
    bool unite(int a, int b){
        //a, bにそれぞれが属するグループの根を入れる
        //uni[a], uni[b]がa, bがそれぞれが属するグループのサイズになる
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a,b); //bの方を大きいものにする
        uni[a] += uni[b];
        uni[b] = a; //大きい方のグループに属するものの親を小さいものの根にする(rootが高速で動くようになる)
        return true;
    }
    //頂点aとbが同じグループかを調べる
    bool isConnected(int a, int b){
        return root(a) == root(b);
    }
    //頂点aを含むグループの頂点数を調べる
    int unisize(int a){
        return -uni[root(a)];
    }
    //グループ数を調べる
    int group_num(void){
        int num = 0;
        int s = uni.size();
        for(int i = 0; i < s; i++) if(uni[i] < 0) num++;
        return num;
    }
};

int main(){
    int n,m; cin >> n >> m;
    vector<int> p(n); rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    union_find u(n);
    int x,y;
    rep(i,m){
        cin >> x >> y;
        x--; y--;
        u.unite(x, y);
    }
    int ans = 0;
    rep(i,n){
        if(p[i] == i) ans++;
        else if(u.isConnected(i,p[i])) ans++;
    }
    cout << ans;
}