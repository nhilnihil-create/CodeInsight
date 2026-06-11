#include <bits/stdc++.h>
using namespace std;

int main() {
  int a=500;
  int N,A;
  
  cin >>N >> A;
  if(N>=0 && N<=10000){
    int ichien;
    ichien= N % a;
    if(A>=ichien){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  else{
    cout <<"Please 1<=N<=10000"<<endl;
  }
}
