#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, M, i;
  double SumT=0, D=1;
  cin>>N>>M;
  
  int T=1900;
  double p=pow(0.5, M), q=1-p;
  int cnt=1;
  while(D>0.01){
    D=(T*M+(N-M)*100)*p*cnt*pow(q, cnt-1);
    SumT+=D;
    cnt++;
  }
  cout<<(int)SumT+1<<endl;
  return 0;
}