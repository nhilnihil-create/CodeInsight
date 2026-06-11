#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a= b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a= b;
    return 1;
  }
  return 0;
}
ll mod= 1e9 + 7;


struct segmenttree {
    ll INF = 0;//一応注意（題意に沿う）
    ll n;         // 葉の数
    vector<ll> dat; // 完全二分木の配列
    segmenttree(ll n_) : n(), dat(n_ * 4, INF) { // 初期化、数列n_個で宣言すると良い（例、segmenttree g(8);）
        ll x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(ll i, ll x) { //i: 更新したい数列の位置(0-index) x:更新する値
        i += n - 1; // i番目は、配列上では n-1+i 番目に格納されている
        dat[i] = x; // 葉の更新
        while (i > 0) {  // 親を辿りながら更新していく
            i = (i - 1) / 2;  // parent
            dat[i] = __gcd(dat[i * 2 + 1], dat[i * 2 + 2]);//足すのならdat+dat
        }
    }
    // [a,b)の最小値取得
    ll query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }
    ll query_sub(ll a, ll b, ll k, ll l, ll r) {// k:現在見ているノードの位置  [l,r):dat[k]が表している区間
        if (r <= a || b <= l) {// 範囲外なら考えない
            return INF;
        } else if (a <= l && r <= b) { // 範囲内なので自身の値を返す
            return dat[k];
        } else {// 一部区間が被る時
            ll vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return __gcd(vl, vr); //足すのならvl+vr
        }
    }
};



int main() {
  int n;
  ll ans=0;
  cin >> n;
  segmenttree g(n);
  ll k[n];
  rep(i,n){
    ll q;
    cin >> q;
    g.update(i,q);
    k[i]=q;
  }

  rep(i,n){
    g.update(i,0);
    chmax(ans,g.query(0,n));
    g.update(i,k[i]);
  }
  cout << ans << endl;
}