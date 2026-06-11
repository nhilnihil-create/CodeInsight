#include <bits/stdc++.h>
using namespace std;

int kakuinowa(int N){
  int sum=0; 
  while(true){
    sum += N%10;
    
    if(N<10) break; 
    else N/=10;
  }
  return sum;
}

int main(){
  int N, Sum, min=1000000000;
  cin >> N;
  for(int i=1; i<N; i++){
    Sum=kakuinowa(i)+kakuinowa(N-i);
    if(Sum<min) min=Sum;
  }
  cout << min << endl;
}