#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,H,W,ans = 0;
  cin >> N >> H >> W;
  vector<long long>A(N);
  vector<long long>B(N);
  for(int i=0; i<N; i++){
   cin >> A[i] >> B[i];
    if(A[i] >= H && B[i] >= W){
      ans++;
    }
  }
  cout << ans << endl;
}
