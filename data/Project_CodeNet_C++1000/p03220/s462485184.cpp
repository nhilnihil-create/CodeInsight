#include<bits/stdc++.h>
using namespace std;

int main(){
  long N,T,A,res,Tc,Min=1000000000;
  cin >> N >> T >> A;
  long H[N];
  for(long i=0;i<N;i++){
    cin >> H[i];
    Tc = T*1000 - H[i]*6;
    if(abs(Tc-A*1000)<Min){
      Min = abs(Tc-A*1000);
      res = i+1;
    }
  }
  cout << res << endl;
  return 0;
}