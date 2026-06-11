#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  int N, M;
  cin >> N >> M;
  int L, R;
  int Lmax = 0;
  int Rmin = INF;
  rep(i, M){
    cin >> L >> R;
    Lmax = max(Lmax, L);
    Rmin = min(Rmin, R);
  }
  int res = max(Rmin - Lmax + 1, 0);
  cout << res << endl;
}
