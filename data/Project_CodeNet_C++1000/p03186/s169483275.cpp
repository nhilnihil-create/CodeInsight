#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9



int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int ans = B + min(C, A+B+1);
  cout << ans << endl;
  return 0;
}
