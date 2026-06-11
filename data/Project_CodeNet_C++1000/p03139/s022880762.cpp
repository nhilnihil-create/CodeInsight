#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int N,A,B,ans;
  cin>>N>>A>>B;
  ans=A+B-N;
  if(ans<0) ans=0;
  cout<<min(A,B)<<" "<<ans<<endl;
}

