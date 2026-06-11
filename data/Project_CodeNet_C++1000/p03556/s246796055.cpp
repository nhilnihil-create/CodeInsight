#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,i=0;
  cin >> N;
  while(true){
    if(i*i>N){
      break;
    }
    else{
      i++;
    }
  }
  cout << (i-1)*(i-1) << endl;
}   