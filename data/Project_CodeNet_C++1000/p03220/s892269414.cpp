#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N,T,A,i,dif,ANS;
  cin>>N>>T>>A;
  
  int ans = 1e9;
  A=1000*A;
  vector<int> H(N);
  for(i=0;i<N;i++){
    cin>>H[i];
    H[i] = T*1000-H[i]*6;
    dif = abs(A-H[i]);
    if (dif < ans){
      ans = dif;
      ANS = i+1;
    }
  }
  cout << ANS;

}