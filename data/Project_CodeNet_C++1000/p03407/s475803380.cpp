#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  if(a+b>=c) co("Yes");
  else co("No");
  return 0;
}
