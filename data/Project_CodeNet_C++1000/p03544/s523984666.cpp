#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N, La = 2, Lb = 1;
  cin >> N;
  
  if(N % 2 == 1){
    for(int i = 0; i < (N-1) / 2; i++){
      La += Lb;
      Lb += La;
    }
    cout << Lb << endl;
  }
  
  else{
    for(int i = 0; i < N / 2; i++){
      La += Lb;
      Lb += La;
    }
    cout << La << endl;
  }
}