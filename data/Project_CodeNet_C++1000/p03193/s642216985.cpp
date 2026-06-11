#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,H,W,A,B;
  cin >> N >> H >> W;
  int ans = 0;
  for (int i = 0; i < N; i++){
    cin >> A >> B;
    if (A >= H && B >= W) ans++;
  }
  cout << ans;
}