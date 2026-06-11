#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<math.h>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define print(x) cout << #x << " = " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;


int main() {
  int A, B;
  cin >> A >> B;

  int ans = 0;
  for (int i = A; i <= B; ++i) {
    string str = to_string(i);
    bool bCheck = true;
    for (int j = 0; j < str.size() / 2; j++) {
      if (str[j] != str[str.size() - j - 1]) {
        bCheck = false;
        break;
      }
    }
    if (bCheck) ans++;
  }

  cout << ans << endl;
  return 0;
}