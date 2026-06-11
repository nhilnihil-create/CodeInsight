#include <bits/stdc++.h>
using namespace std;

int main() {
  int N , N_, a ;
  cin>>N;
  N_=N;
  a=0;
  for(int i=0 ; i<N ; i++){
    int b ;
    b=N_%10;
    N_ = (N_-b)/10;
    a +=b;
  }
  if(N%a==0){
  cout<< "Yes" << endl;
  }
  else{
    cout<<"No"<<endl;
  }
}