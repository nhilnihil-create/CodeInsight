#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

struct BIT{
private:
    vector<ll> node;
    ll n ;

public:
    BIT(ll _n) : node(_n + 1,0), n(_n){}

    ll rui(ll i){
        ll s = 0;
        while(i > 0){
            s += node.at(i);
            i -= (i & -i);
        }
        return s;
    }

    ll sum(ll i, ll j){ //[i,j]の総和
        return rui(j) - rui(i-1);
    }

    void add(ll i, ll x){ //i番目にxを加える (累積和用)
        while(i<=n){
            node[i] += x;
            i += (i&-i);
        }
    }

    void setval(ll i,ll x){ //i番目をxにする (最大値用)
        while(i<=n){
            node[i] = max(node[i], x);
            i += (i&-i);
        }
    }

    ll maxval(ll i){ //[0,i]の最大値を返す
        ll ret = 0;
        while(i>0){
            ret = max(ret,node[i]);
            i -= (i&-i);
        }
        return ret;
    }
};

struct SegmentTree {
private:
    ll n;
    vector<ll> node;
    //int nとvector<int> nodeの2つを変数に持つ

public:
    //初期化処理
    SegmentTree(vector<ll> v) {
        ll sz = v.size(); //vは扱う配列の長さ
        n = 1; while(n < sz) n *= 2; //nはvの配列を入れるために必要なseg treeの葉の数
        node.resize(2*n-1, 0); //segtreeでは全部で2n-1の配列が必要 ★演算によって単位元を変える
        for(int i=0; i<sz; i++) node[i+n-1] = v[i]; //segtreeの葉の部分に扱う配列を埋め込む
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]); //★演算によって変える場所　segtreeを作る(注目しているnode iの子ノードを見て二項演算をして、node iの値を決定する)
    }

    void update(ll x, ll val) {
        x += (n - 1); //配列のx番目の要素を更新しようとするとき、segtreeで対応する要素はx+n-1番目である
        node[x] = val; //segtree上で値を更新
        while(x > 0) { //葉から根に向かってsegtreeの要素を更新していく
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]); //★演算によって変える
        }
    }

    ll getmax(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        //求めたいのは区間[a,b)の中で演算しつづけた結果(たとえばこの区間の最小値)
        //自分がいるノードのindex(何階にいるか？)
        //ノードkは元の配列でいうとどの区間をカバーしているか？
        if(r < 0) r = n; //最初に呼び出す時はノードk=0はsegtreeの根なので区間は[0,n)を指す
        if(r <= a || b <= l) return 0; //今のノードが求める区間と無関係の場合は、最終的な答えに影響しない単位元(最小値を求めたい場合は単位元はINF)を返す 演算によって変える
        if(a <= l && r <= b) return node[k]; //今見ている区間[l,r)が答えを求めたい区間[a,b)に完全に含まれるなら、この区間について演算し続けた結果(=node[k];例えば最小値)を返す

        //上記に当てはまらない場合
        //kの子ノードを見に行って、再帰的に処理を行う k=0の場合はノード1と2を見る
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2); //kの子ノード(left)の子孫のうち、求めたい区間に含まれる要素について演算し続けた結果を返す
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r); //kの子ノード(right)の子孫のうち、求めたい区間に含まれる要素について演算し続けた結果を返す
        return max(vl, vr); //演算によって変える場所 子ノードの子孫のうち、演算しつづけた結果を返す
    }
};

int main(){
    ll n ; cin >> n;
    vector<ll> h(n),a(n);
    rep(i,n){
        cin >> h.at(i);
    }
    rep(i,n) cin >> a.at(i);

    BIT tree(n);

    rep(i,n){
        ll mxm = tree.maxval(h.at(i)-1);
        //cout << i << endl;
        tree.setval(h.at(i),mxm+a.at(i));
        //cout << i << endl;
        //cout << mxm << endl;
    }
    cout << tree.maxval(n) << endl;
    return 0;
}