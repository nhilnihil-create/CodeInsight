#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, ans, L1, L0;
  cin >> N;
  
  L1=1;
  L0=2;
  ans=1;
  
  for(int i=2; i<=N; i++){
    ans = L1 + L0;
    L0=L1; L1=ans;
  }
  
  cout << ans << endl;
}
