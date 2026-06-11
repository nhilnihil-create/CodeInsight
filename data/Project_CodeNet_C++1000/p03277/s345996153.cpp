#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

template<typename T> struct BinaryIndexedTree {
  vector<T> data;
  BinaryIndexedTree(int sz) { data.assign(++sz, 0); }
  T sum(int k) {
    T ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
  void add(int k, T x) { for (++k; k < data.size(); k += k & -k) data[k] += x; }
};

template<typename T> ll InversionNumber(vector<T> &v) {
  ll sz = v.size(), ret = 0;
  vector<T> rev, v_cp = v; sort(v_cp.begin(), v_cp.end());
  for (auto e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
  BinaryIndexedTree<T> bit(sz);
  for (int i = 0; i < sz; ++i) {
    ret += i - bit.sum(rev[i]);
    bit.add(rev[i], 1);
  }
  return ret;
}

int N;
ll M;
vector<int> A;

bool check(int k) {
  vector<int> B(N), B_sum(N + 1, 0);
  for (int i = 0; i < N; ++i) B[i] = (A[i] >= k) ? 1 : -1;
  for (int i = 0; i < N; ++i) B_sum[i + 1] = B_sum[i] + B[i];
  return (M - InversionNumber(B_sum) >= (M + 1) / 2);
}

signed main() {

  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  if (N == 1) {
    cout << A[0] << endl;
    return 0;
  }

  M = N * (N + 1) / 2;

  ll ok = 0, ng = 1e9 + 1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

}
