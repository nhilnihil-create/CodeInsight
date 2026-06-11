#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> vec(N);
  int64_t co = 0;
  int64_t ans = 0;
  rep(i, N) {
    cin >> vec.at(i);
  }
  while(true) {
    rep(i, N) {
      if(vec.at(i) % 2 == 0) {
        co++;
        vec.at(i) = vec.at(i) / 2;
      }
    }
    if(co < N) {
      break;
    }
    ans++;
    co = 0;
  }
  cout << ans << endl;
}