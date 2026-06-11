#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
//typedef vector<vector<P> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


//抽象化したセグメント木
//SegmentTree<T>(n,fx,ex):モノイド(集合T,二項演算fx, 単位元ex)についてサイズnで構築
template<typename T>
struct  SegmentTree{
    using FX = function<T(T,T)>;
    int n;
    FX fx;
    const T ex;
    vector<T>node;

    //初期化(datは単位元exで初期化する)
    SegmentTree(int n_, FX fx_, T ex_) : n(),fx(fx_),ex(ex_),node(n_*4,ex_){
        int x = 1;
        while(n_ > x)x*=2;
        n = x;
    }
    
    void set(int i, T x){//最下段の要素の構築
        node[i+n-1]=x;
    }

    void build(){
        for(int i=n-2;i>=0;i--){
            node[i]=fx(node[2*i+1],node[2*i+2]);
        }
    }

    //i番目の要素の更新,計算量O(log(n))
    void update(int i, T x){
        i += n-1;
        node[i]=x;
        while(i>0){
            i=(i-1)/2;
            node[i]=fx(node[i*2+1],node[i*2+2]);
        }
    }

    //query(a,b)は[a,b)全てにfxを作用させた値の取得,計算量はO(log(n))
    T query(int a,int b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(int a,int b,int k,int l,int r){
        if(r<=a || b<=l){//区間が全くかぶらない時は単位元を返す
            return ex;
        }
        if(a<=l && r <= b){//区間を完全に覆っている時
            return node[k];
        }
        T vl = query_sub(a,b,k*2+1,l,(l+r)/2);
        T vr = query_sub(a,b,k*2+2,(l+r)/2,r);
        return fx(vl,vr);
    }
};


//入力
ll n;

int main(){
    cin >> n;
    auto fx = [](int x1,int x2) -> int{
        return __gcd(x1,x2);
    };
    int ex = 0;
    SegmentTree<int> seg(n,fx,ex);
    rep(i,n){
        int a;
        cin >> a;
        seg.set(i,a);
    }
    seg.build();
    int ans = 0;
    rep(i,n){
        int now1 = seg.query(0,i);
        int now2 = seg.query(i+1,n);
        int now = __gcd(now1,now2);
        chmax(ans,now);
    }
    cout << ans << endl;
    return 0;
}