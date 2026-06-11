#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int ans=0;
  if(A>B)swap(A, B);
  if(B>C)swap(B, C);
  if(A%2==B%2 && A%2==C%2)ans = (C*2-A-B)/2;
  else if(A%2==B%2)ans=(C*2-A-B)/2;
  else ans = (C*2-A-B)/2+2;
  
  cout << ans <<endl;
}