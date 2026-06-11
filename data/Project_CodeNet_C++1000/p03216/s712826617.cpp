#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main() {
  int N;
  string S;
  cin >> N >> S;
  // f : 場所 
  // s : その場所より前にある'M'の個数
  vector<int> Df;
  vector<int> Cf;
  vector<int> Ds;
  vector<int> Cs;
  int Mcnt = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'D') {
      Df.push_back(i);
      Ds.push_back(Mcnt);
    } else if (S[i] == 'C') {
      Cf.push_back(i);
      Cs.push_back(Mcnt);
    } else if (S[i] == 'M') {
      Mcnt++;
    }
  }

  int Dsz = Df.size();
  int Csz = Cf.size();
  BIT<ll> bit(Csz);

  for (int i = 0; i < Csz; i++) {
    bit.add(i,Cs[i]);
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int k;
    cin >> k;
    ll ans = 0;
    for (int i = 0; i < Dsz; i++) {
      ll l = lower_bound(Cf.begin(),Cf.end(),Df[i]) - Cf.begin();
      ll r = lower_bound(Cf.begin(),Cf.end(),Df[i]+k) - Cf.begin() - 1;
      ll res = bit.sum(l,r+1);
      res -= Ds[i] * (r - l + 1);
      ans += res;
    }
    cout << ans << endl;
  }
  return 0;
}