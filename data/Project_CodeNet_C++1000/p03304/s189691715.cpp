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
typedef long long ll;

int main(){

  double N, M, D; cin >> N >> M >> D;

  double ans;
  if (D != 0){
    ans = 2 * (N - D) / (N * N) * (M - 1);
  }else{
    ans = (M - 1) / N;
  }
  cout << setprecision(32) << ans << endl;

  return 0;
}
