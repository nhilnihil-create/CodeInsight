#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;



int main(){
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];
  sort(ALL(x));
  sort(ALL(y));
  int Z = min(Y, y[0]);
  if (Z > X && x[n-1] < Z) cout << "No War\n";
  else cout << "War\n";

}