#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // Collatz Problem
  int s; cin >> s;
  map<int,int> am;
  int n = s;
  int i=1, m = 0;
  while(i<=1000000) {
    am[n] = i;
    if (n % 2 == 0) n /= 2;
    else n = 3 * n + 1;
    i++;
    if (am.count(n)) {
      m = i;
      break;
    }
  }
  cout << m << endl;
  return 0;
}
