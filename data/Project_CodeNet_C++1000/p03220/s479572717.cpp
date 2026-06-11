#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,T,A;
  double C = 10000;
  int ans;

  cin >> N >> T >> A;
  for(int i=1;i<=N;++i){
    int h; cin >> h;
    if(C > abs(A-(T-0.006*h))){
      C = abs(A-(T-0.006*h));
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
