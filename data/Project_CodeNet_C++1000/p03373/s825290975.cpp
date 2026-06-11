#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans(1e9);
  ans=min(ans,min(X,Y)*2*C+abs(X-Y)*2*C); 
  ans=min(ans,A*X+B*Y);
  if (X>Y) ans=min(ans,2*C*Y+(X-Y)*A);
  else ans=min(ans,2*C*X+(Y-X)*B);
  cout << ans << endl;
  return 0;
}
