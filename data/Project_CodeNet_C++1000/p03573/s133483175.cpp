#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C;
  int ans;
  cin >> A >> B >> C;
  if(A == B)
    ans = C;
  if(A == C)
    ans = B;
  if(B == C)
    ans = A;
  cout << ans << "\n";
  return 0;
}
