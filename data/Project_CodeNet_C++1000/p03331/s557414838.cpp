#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int N;
  cin >> N;
  
  int ans=100000;
  for(int i=1; i<N; i++){
    int A = i;
    int B = N - A;
    int total=0;
    
    for(int j=0; j<5; j++){
      total += A%10 + B%10;
      A /= 10;
      B /= 10;
    }
    
    if(ans > total){
      ans = total;
    }
  
  }
  
 cout << ans << endl;
  
}
