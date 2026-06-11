#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  
  cin >> N;
  
  int t = N,tmp = 0;
  
  while(t > 0){
    tmp += t % 10;
    t = t / 10;
  }
  
  if(N % tmp == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
}