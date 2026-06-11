#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  
  int A[n];
  int ans = 0;
  
  rep(i,n){
    A[i] = i+1;
    int count = 0;
    
    while(true){
      count += A[i]%10;
      if(A[i]/10 == 0) break;
      A[i] = A[i]/10;
    }

    if(count >=a && count <= b) ans += i+1; 
  }
  
  cout << ans << endl;
  return 0;
}
    
