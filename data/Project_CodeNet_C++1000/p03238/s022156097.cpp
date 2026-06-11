#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#define rep(i,n) for (int i = 0; i< (n); i++)
using namespace std;

double kitai(double x){
  double sum = 0;
  for(int i = 1; i<x+1; i++){
  	sum += i * (1/x);
  }
  return sum;
}

int main() {
  int N,A,B;
  
  cin>>N;
  
  if(N == 1) cout<<"Hello World"<<endl;
  
  else{
    cin>>A>>B;
    cout<<A+B<<endl;
  }
  
  
  return 0;
}

