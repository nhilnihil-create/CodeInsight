#include <bits/stdc++.h>
using namespace std;

int main() {
  double H,W,N,M,d;
  cin >>N>>M>>d;
  double ans;
  ans=0;
  if(d!=0){
    ans=2*(N-d)/(N*N)*(M-1);
  }
  else{
    ans=(M-1)/N;
  }
  cout << std::setprecision(10) << ans<<endl;
}
 