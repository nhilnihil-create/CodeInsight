#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t K,A,B;
  cin >> K >> A >> B;
  if(B<=A+2){
    cout << 1+K << endl;
  }else{
    if(K<A+1){
      cout << 1+K << endl;
    }else{
      int64_t ans=B;
      K-=(A+1);
      int64_t count=K/2;
      ans+=(B-A)*count+(K%2);
      cout << ans << endl;
    }
  }
  return 0;
}
