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
const long long INF = 1e16;
typedef long long ll;

int main(){
  int N; cin >> N;

  vector <int> C(N);
  int M = 0;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    if(M < C[i]) M = C[i];
  }

  vector <ll> ref(M);

  ll ans = 1;
  ref[C[0] - 1]++;
  for (int i = 1; i < N; i++){
    if(C[i] != C[i - 1]){
      int color = C[i] - 1;
      ans += ref[color];
      ans %= nmax;
      ref[color] = ans;
    }
  }
  cout << ans << endl;


  return 0;
}
