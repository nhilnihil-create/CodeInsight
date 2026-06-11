#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  int a[N]; rep(i, N) cin >> a[i];

  int max_abs = 0;
  rep(i, N) if (abs(a[max_abs]) < abs(a[i])) max_abs = i;

  cout << 2*N-1 << endl;
  rep(i, N) cout << max_abs+1 << " " << i+1 << endl;
  if (a[max_abs] < 0) for(int i=N; i>1; i--) cout << i << " " << i-1 << endl;
  else for(int i=1; i<N; i++) cout << i << " " << i+1 << endl;
  return 0;
}