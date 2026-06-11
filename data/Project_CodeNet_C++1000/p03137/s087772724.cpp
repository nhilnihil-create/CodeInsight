#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> X(M); REP(i, M) cin >> X[i];
  if(N >= M) {
    cout << 0 << endl;
  } else {
    vector<ll> tmp(M - 1, 0);
    sort(all(X));
    REP(i, M - 1) {
      tmp[i] = X[i + 1] - X[i];
    }
    sort(all(tmp), greater<ll>());
    ll a = accumulate(all(tmp), 0LL);
    REP(i, N - 1) {
      a -= tmp[i];
    }
    cout << a << endl;
  }
}
