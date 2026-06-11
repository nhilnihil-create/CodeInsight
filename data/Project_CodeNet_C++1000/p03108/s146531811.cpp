#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

//以下、素集合と木は同じものを表す
class UnionFind {
public:
    vector<ll> parent; //parent[i]はiの親
    vector<ll> siz; //素集合のサイズを表す配列(1で初期化)
    map<ll,vector<ll>> group;//素集合ごとに管理する連想配列(keyはそれぞれの素集合の親、valueはその素集合の要素の配列)

    //コンストラクタ
    UnionFind(ll n):parent(n),siz(n,1){ 
        //全ての要素の根が自身であるとして初期化
        for(ll i=0;i<n;i++){parent[i]=i;}
    }

    //データxの属する木の根を取得(経路圧縮も行う)
    ll root(ll x){
        if(parent[x]==x) return x;
        return parent[x]=root(parent[x]);//代入式の値は代入した変数の値なので、経路圧縮できる
    }

    //xとyの木を併合
    void unite(ll x,ll y){
        ll rx=root(x);//xの根
        ll ry=root(y);//yの根
        if(rx==ry) return;//同じ木にある時
        //小さい集合を大きい集合へと併合(ry→rxへ併合)
        if(siz[rx]<siz[ry]) swap(rx,ry);
        siz[rx]+=siz[ry];
        parent[ry]=rx;//xとyが同じ木にない時はyの根ryをxの根rxにつける
    }

    //xとyが属する木が同じかを判定
    bool same(ll x,ll y){
        ll rx=root(x);
        ll ry=root(y);
        return rx==ry;
    }

    //xの素集合のサイズを取得
    ll size(ll x){
        return siz[root(x)];
    }

    //素集合をそれぞれグループ化
    void grouping(ll n){
        //経路圧縮を先に行う
        rep(i,n)root(i);
        //mapで管理する(デフォルト構築を利用)
        rep(i,n)group[parent[i]].push_back(i);
    }
};

int main(){
    ll n,m;cin>>n>>m;
    vector<ll>a(m),b(m);
    rep(i,m){cin>>a[i]>>b[i];a[i]--;b[i]--;}
    UnionFind u(n);
    ll ans=n*(n-1)/2;
    deque<ll>d;
    d.push_front(ans);
    for(int i=m-1;i>=1;--i){
        if(u.same(a[i],b[i]))d.push_front(ans);
        else{
            ans-=(u.size(a[i]))*(u.size(b[i]));
            d.push_front(ans);
        }
        u.unite(a[i],b[i]);
    }
    while(!d.empty()){
        ll x=d.front();
        d.pop_front();
        cout<<x<<endl;
    }
    return 0;
}
