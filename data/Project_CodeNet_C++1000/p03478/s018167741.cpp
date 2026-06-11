#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int N,A,B;
  cin >> N >> A >> B;
  
  int ans=0;
  for(int i=1; i<N+1; i++){
    int c=0, t=i;
    for(int j=0; j<5; j++){
      c += t % 10;
      t /= 10;
    }
    if(A <= c && c <= B){
      ans += i;
    }
  }

 cout << ans << endl;
  
}
