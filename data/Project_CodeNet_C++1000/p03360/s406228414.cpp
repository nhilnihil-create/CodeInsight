#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,K,ans,sum; cin >> A >> B >> C >> K;
  ans = max(max(A,B),C);
  sum= A + B + C;
  for(int i=0; i<K; i++) ans *=2;
  
  cout << ans + sum - max(max(A,B),C)  << endl;
}