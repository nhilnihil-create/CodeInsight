#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M, ans;
  cin >> N >> M;
  
  ans = (N - M)*100 + M*1900;
  for (int i = 0; i < M; i++){
    ans *= 2;
  }
  
  cout << ans << endl;
}