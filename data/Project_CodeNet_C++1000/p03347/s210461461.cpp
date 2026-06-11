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
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 0, now = 0;

  for (int i = N - 1; i >= 0; i--){
    if (now > A[i]){
      ans = -1;
      break;
    }else if(now == A[i]){
      now--;
    }else{
      ans += A[i];
      now = A[i] - 1;
    }
  }
  if (A[0] != 0){
    ans = -1;
  }
  
  
  cout << ans << endl;

  return 0;
}
