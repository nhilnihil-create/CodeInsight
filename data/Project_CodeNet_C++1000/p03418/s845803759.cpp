#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Rmin;
  cin >> N >> Rmin;

  int64_t ans= 0;
  for(int div= Rmin+1; div<=N; div++){
    ans+= (N/div)*((div-1)- (Rmin-1)) + max(N%div- max(Rmin-1,0), 0);
  }

  cout << ans << endl;
}