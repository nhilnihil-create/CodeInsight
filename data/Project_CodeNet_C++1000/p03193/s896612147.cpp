#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, H, W;
  cin >> N >> H >> W;
  vector<int> A(N);
  vector<int> B(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i) >> B.at(i);
  }
  int ans = 0;
  for(int i = 0; i < N; i++){
    if(A.at(i) >= H && B.at(i) >= W)ans++;
  }
  cout << ans << endl;
}