#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
int main() {
  vector<int> likenum;
  for (int i = 1; i <= 100000; i+=2) {
    if (is_prime(i) && is_prime((i+1)/2)) {
      likenum.push_back(i);
    }
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l,r;
    cin >> l >> r;
    auto itr = lower_bound(likenum.begin(),likenum.end(),l);
    auto itr2 = upper_bound(likenum.begin(),likenum.end(),r);
    cout << itr2 - itr << endl;
  }
  return 0;
}