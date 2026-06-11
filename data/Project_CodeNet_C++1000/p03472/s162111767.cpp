#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;


int main() {
  ll n,h; cin >> n >> h;
  ll max_a = 0;
  vector<ll> b(n);
  rep(i,n) {
    ll tmp_a,tmp_b;
    cin >> tmp_a >> tmp_b;
    b.push_back(tmp_b);
    max_a = max(max_a,tmp_a);
  }

  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());

  ll ans_count = 0;
  ll current_pos = 0;

  while(h > 0) {
    ans_count++;
    if(b[current_pos] <= max_a) {
      h -= max_a;
      continue;
    }
    h -= b[current_pos];
    current_pos++;
  }

  cout << ans_count << endl;
}
