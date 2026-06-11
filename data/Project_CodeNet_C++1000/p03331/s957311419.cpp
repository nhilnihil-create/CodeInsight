#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N,i,A,B;
  cin>>N;
  int cnt = 0;
  int ans = 1e5;

  for (i=1;i<N;i++){
    A=i;
    B=N-i;
    
    int Asum=0;
    int Bsum=0;
    while(A>=1){
      Asum=Asum+A%10;
      A/=10;
    }
    while(B>=1){
      Bsum=Bsum+B%10;
      B/=10;
    }
    ans = min(ans, Asum+Bsum);
  }
  cout << ans << endl;
}