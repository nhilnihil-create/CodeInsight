#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
class SegmentTree
{
private:
  using Fn = function<T(T, T)>;
  int N;
  vector<T> dat;
  T unit;
  Fn func;

public:
  SegmentTree() {}
  SegmentTree(int n_, Fn func_, T unit_) : func(func_), unit(unit_)
  {
    N = 1;
    while (N < n_)
      N *= 2;
    dat.assign(2 * N - 1, unit);
  }
  SegmentTree(const vector<T> &v, Fn func_, T unit_) : func(func_), unit(unit_)
  {
    N = 1;
    int sz = v.size();
    while (N < sz)
      N *= 2;
    dat.resize(2 * N - 1);
    for (int i = 0; i < N; ++i)
      dat[i + N - 1] = (i < sz ? v[i] : unit);
    for (int i = N - 2; i >= 0; --i)
      dat[i] = func(dat[i * 2 + 1], dat[i * 2 + 2]);
  }

  // k 番目の要素を a に変更
  void update(int k, T a)
  {
    k += N - 1;
    dat[k] = a;
    while (k > 0)
    {
      k = (k - 1) / 2;
      dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  // k 番目の要素を取得
  T get(int k) { return dat[k + N - 1]; }

  // 区間 [l, r) の和を取得
  T query(int l, int r)
  {
    T vl = unit, vr = unit;
    for (l += (N - 1), r += (N - 1); l < r; l >>= 1, r >>= 1)
    {
      if ((l & 1) == 0)
        vl = func(vl, dat[l]);
      if ((r & 1) == 0)
        vr = func(vr, dat[--r]);
    }
    return func(vl, vr);
  }
};
int main(){
    ll n;
    cin>>n;
    auto c=[](ll a,ll b) { return __gcd(a,b); };
    SegmentTree<ll> sg(n,c,0);
    rep(i,n) {
        ll x;
        cin>>x;
        sg.update(i,x);
    }
    ll ans=0;
    rep(i,n) {
        ll kotae= __gcd(sg.query(0, i), sg.query(i+1,n));
        if(ans<kotae){
          ans=kotae;
        }
    }
    cout<<ans<<endl;
}
