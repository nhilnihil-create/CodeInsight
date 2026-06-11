#include <bits/stdc++.h>
using namespace std;

long long int lucas(int a){
  if(a==1){
    return 2;
  }
  if(a==2){
    return 1;
  }
  if(a==41){
    return 228826127;
  }
  if(a==42){
    return 370248451;
  }
  if(a==71){
    return 425730551631123;
  }
  if(a==72){
    return 688846502588399;
  }
  return lucas(a-1) + lucas(a-2);
}

int main(){
  int N;
  cin >> N;
  cout << lucas(N+1) << endl;
}