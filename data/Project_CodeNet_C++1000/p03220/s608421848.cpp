#include <bits/stdc++.h>
using namespace std;

int N, T, A, H[1100];

int main(){

  cin >> N >> T >> A;

  for(int i; i < N; ++i){
    cin >> H[i];
  }

  double dmin = 1e9, ans = -1;

  for(int i = 0; i < N; ++i){
    double t = T - H[i] * 0.006;
    double d = abs(A - t);
    if(d < dmin){
      dmin = d;
      ans = i;
    }
  }

  cout << ans + 1 << endl;

  return 0; 
}