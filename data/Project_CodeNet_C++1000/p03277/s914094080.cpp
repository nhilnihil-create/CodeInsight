#include<bits/stdc++.h>
using namespace std;

template<typename T> T merge_count(vector<T>& a) {
  if(a.size() <= 1) return 0;
  T cnt = 0;
  vector<T> b(a.begin(), a.begin() + a.size() / 2);
  vector<T> c(a.begin() + a.size() / 2, a.end());
  cnt += merge_count(b) + merge_count(c);
  T ai = 0, bi = 0, ci = 0;
  while(ai < a.size()) {
    if(bi < b.size() && (ci == c.size() || b[bi] < c[ci])) {
      a[ai++] = b[bi++];
    } else {
      cnt += a.size() / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return cnt;
}

int main() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  for(auto& i: A) cin >> i;

  auto M = N*(N+1)/2;

  auto ok = [&](auto X) {
    vector<long long> S = {0};
    for(auto i: A) S.emplace_back(S.back() + (i<X ? 1: -1));
    return (M+1)/2 <= merge_count(S);
  };

  long long l = 1, h = 1e9+1;
  while(1 < h-l) {
    auto m = (l + h) / 2;
    if(ok(m)) l = m;
    else      h = m;
  }
  cout << l << endl;
}
