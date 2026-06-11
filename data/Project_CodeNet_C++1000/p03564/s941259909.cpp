#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  if(K==1){
    cout << N+1 << endl;
  }
  else if(K==2){
    cout << 2*N << endl;
  }
  else if(K==3||K==4){
    if(N!=1){
      cout << 4+K*(N-2) << endl;
    }
    else{
      cout << 2 << endl;
    }
  }
  else if(K==9||K==10){
    if(N==1){
      cout << 2 << endl;
    }
    else if(N==2){
      cout << 4 << endl;
    }
    else if(N==3){
      cout << 8 << endl;
    }
    else if(N==4){
      cout << 16 << endl;
    }
    else{
      cout << 16+(N-4)*K << endl;
    }
  }
  else{
    if(N==1){
      cout << 2 << endl;
    }
    else if(N==2){
      cout << 4 << endl;
    }
    else if(N==3){
      cout << 8 << endl;
    }
    else{
      cout << 8+K*(N-3) << endl;
    }
  }
}