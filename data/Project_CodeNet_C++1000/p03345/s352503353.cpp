#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int64_t A,B,C,K;
  cin >> A >> B >> C >> K;
  int64_t ans = A-B;
  if(abs(ans)>1000000000000000000){
    cout << "Unfair" << endl;
  }
  else if(K%2 == 0){
    cout << ans << endl;
  }
  else{
    cout << -1*ans << endl;
  }

}

