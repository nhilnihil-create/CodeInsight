#include <bits/stdc++.h>
using namespace std;

int A(int N){
    return 2*N;
}

int B(int N,int K){
    return N + K;
}
int main(void){
    
  int N,K,ans=1;
  cin >> N >> K;
  for(int i=0;i<N;i++){
      int a = A(ans);
      int b = B(ans,K);
      
      if(a < b) ans = a;
      else ans = b;
  }
  
  cout << ans << endl;
}