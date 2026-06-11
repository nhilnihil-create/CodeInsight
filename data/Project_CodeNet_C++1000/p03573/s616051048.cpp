#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,ans;
  cin >> A >> B >> C;
  if(A==B) ans=C;
  if(B==C) ans=A;
  if(C==A) ans=B;
  cout << ans << endl;
}