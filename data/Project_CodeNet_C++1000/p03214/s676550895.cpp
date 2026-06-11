#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

void solve(long long N, std::vector<long long> a) {
    long long sum = 0;
    int idx = -1;
    int dist = 1e9;
    for(int i = 0 ; i < N ; i++){
      sum += a[i];
    }

    for(int i = 0 ; i < N ; i++){
      if( dist > abs(a[i] * N - sum) ){
        dist = abs(a[i] * N - sum);
        idx = i;
      }
    }
    cout << idx << endl;

}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N - 1 - 0 + 1);
  for (int i = 0; i < N - 1 - 0 + 1; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, std::move(a));
  return 0;
}
