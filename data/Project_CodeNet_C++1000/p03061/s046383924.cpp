#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
  SegmentTree(vector<T> v, Fn func_, T unit_) : func(func_), unit(unit_)
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

  // 区間 [l, r) のgcdを取得
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

int gcd(int m, int n) {//最大公約数
    if (n == 0)return m;
    return gcd(n, m % n);
}//gcd

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  auto f = [](int a, int b) {return gcd(a,b);};
  SegmentTree<int> sg(a,f,0);
  int max_ans=1;
  rep(ai,n){
    int ans;
    int x=sg.get(ai);//hozon
    sg.update(ai,0);//ai=0
    ans=sg.query(0,n);//gcd
    max_ans=max(max_ans,ans);
    sg.update(ai,x);//modosu
  }
  cout<<max_ans<<endl;
}