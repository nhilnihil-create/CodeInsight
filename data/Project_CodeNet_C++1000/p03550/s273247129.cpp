#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N, Z, W; cin >> N >> Z >> W;

  int A[N + 1];
  A[0] = W;
  for (int i = 1; i <= N; i++) cin >> A[i];

  cout << max(abs(A[N] - W), abs(A[N] - A[N - 1])) << endl;
  return 0;
}
