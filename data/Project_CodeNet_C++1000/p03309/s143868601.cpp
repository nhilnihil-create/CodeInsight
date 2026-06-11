#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  int n;
  cin >> n;
  vll a(n);
  rep(i,n) {
    cin >> a.at(i);
    a.at(i) -= (i+1);
  }
  auto f = [&](ll p) {
    ll ret = 0;
    rep(i,n) ret += abs(a.at(i)-p);
    return ret;
  };
  sort(a.begin(), a.end());
  cout << min(f(a.at(n/2)),f(a.at(n/2)+1)) << endl;
  return 0;
}