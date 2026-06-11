#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef tuple<int, int, int> ituple;

// const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (100000 + 2)

void exec(){
  bitset<4000005> bs(1);
  int n, a, sum = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);

    sum += a;
    bs = bs | (bs << a);
  }

  int ans = 0;
  for (int i = (sum / 2 + (sum % 2)); i <= sum; i++) {
    if (bs.test(i)) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
