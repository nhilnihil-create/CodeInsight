#include <bits/stdc++.h>
using namespace std;

double ans = 1e9;
int main() {
  int N, T, A;
  cin >> N >> T >> A;
  double tmp[N];
  for(int i = 0; i < N; i++){
    double h; cin >> h;
    tmp[i] = T - h * 0.006;
  }
  
  for(int i = 0; i < N; i++){
    ans = min(ans, abs(tmp[i]-A));
  }
  for(int i = 0; i < N; i++){
    if(ans==abs(A-tmp[i])){
      cout << i+1 << endl;
      return 0;
    }
  }
}
