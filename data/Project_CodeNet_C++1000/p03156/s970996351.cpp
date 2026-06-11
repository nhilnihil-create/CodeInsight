#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int N, A, B; cin >> N >> A >> B;
  int x=0, y=0, z=0;
  rep(i, N) {
    int P; cin >> P;
    if (P<=A) x++;
    else if (P<=B) y++;
    else z++;
  }
  int result = min(x, min(y,z));
  cout << result << endl;
  return 0;
}