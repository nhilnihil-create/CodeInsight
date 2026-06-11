#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

ll s(ll x) {
  ll r = 0;
  while(x) {
    r+=x%10;
    x/=10;
  }
  return r;
}
ll llcmp(ll a, ll b) {
  // a/s(a) > b/s(b)
  return a*s(b) < b*s(a);
}

ll getNext(ll n) {
  vector<ll> cand;
  cand.push_back(++n);
  ll mod = 10;
  while(n%mod != n) {
    cand.push_back(n - (n%mod) + mod - 1);
    mod *= 10;
  }
  sort(cand.begin(), cand.end(), llcmp);
  return cand[0];
}

void solve() {
  int n;
  cin >> n;
  cout << "1\n";
  ll curr = 1;
  while(--n) {
    curr = getNext(curr);
    cout << curr << "\n";
  }
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":" << "\n";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
