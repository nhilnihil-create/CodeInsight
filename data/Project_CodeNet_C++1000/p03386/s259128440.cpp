#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, k; cin >> a >> b >> k;
  rep(i,b-a+1) {
    if (a+i < a+k || b-k < a+i) {
      cout << a+i << endl;
    }
  }
  return 0;
}