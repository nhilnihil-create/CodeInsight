#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int ans= INT_MAX;
  for(int bufA=1; 2*bufA <= N; bufA++){
    int A= bufA;
    int B= N- A;
    int digitsum= 0;
    while(B > 0){
      digitsum+= A%10+ B%10;
      A/= 10;
      B/= 10;
    }

    ans= min(ans, digitsum);
  }

  cout << ans << endl;
}