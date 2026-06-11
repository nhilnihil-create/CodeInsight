#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(ll (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
// constexpr ll mod = 1e9+7;


int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  int ans = 0;
  REP(i, N){
    cin >> a[i];
    while(a[i] % 2 == 0){
      a[i] /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}