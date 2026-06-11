#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, X;
  bool ans = true;
  cin >> A >> B >> X;
  if(A + B < X || A > X)
    ans = false;
  if(ans) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
