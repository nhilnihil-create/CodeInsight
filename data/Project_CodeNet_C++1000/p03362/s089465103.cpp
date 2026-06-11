#include<bits/stdc++.h>
using namespace std;

int isprime(int N){
  int S=(int)sqrt(N);
  int Ans=1;
  if(N==1){
    return 0;
  }
  for(int i=2; i<=S; i++){
    if(N%i==0){
      Ans=0;
      break;
    }
  }
  return Ans;
}

int main(){
  int N;
  cin >> N;
  vector<int> P(1, 0);
  for(int i=1; i<1382; i+=5){
    if(isprime(i)==1){
      P.push_back(i);
    }
  }
  for(int i=1; i<N+1; i++){
    cout << P.at(i) << " ";
  }
  cout << endl;
}