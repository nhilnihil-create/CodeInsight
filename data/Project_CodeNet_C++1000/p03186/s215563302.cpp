#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,ans;
  cin>>A>>B>>C;
  
  if (A+B<C-1) ans=(A+B+1)+B;
  else ans=B+C;
  
  cout<<ans<<endl;
  
  return 0;
  
}