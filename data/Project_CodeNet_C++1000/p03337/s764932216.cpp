#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int A,B;

  cin >> A >> B ;

  int a=A+B;
  int b=A-B;
  int c=A*B;

  int ans=max(a,b);

  ans=max(ans,c);

  cout << ans << endl;  
 
  return 0;
}