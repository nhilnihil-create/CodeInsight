#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  cin >> N >> A;
  
  int change = N%500;
  
  if(0<=change && change <= A){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}