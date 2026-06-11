#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,P,j;
  cin >> N >> P;
  long long Q=P;
  long long A=1;
  if(N==1){cout << P << endl;}
  else if(N>=40){cout << 1 << endl;}
  else if(N==2){
    for(long long i=1000000;i>=2;i--){
      if(P%(i*i)==0){cout << i << endl; return 0;}
    }
    cout << 1 << endl; 
  }
  else{
    for(long long i=10000;i>=2;i--){
      P=Q;
      for(j=0;j<N;j++){
        if(P%i==0){P=P/i;}
        else{break;}
      }
      if(j==N){cout << i << endl; return 0;}
    }
    cout << 1 << endl;
  }
}
