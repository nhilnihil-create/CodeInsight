#include <bits/stdc++.h>
using namespace std;


int main() {
  string N;
  cin >> N;
  
  for(int i; i < N.size(); i++){
    if(N[i]=='1'){
      N.at(i) = 'x';
    }
    if(N[i]=='9'){
      N.at(i) = '1';
    }
    if(N[i]=='x'){
      N.at(i) = '9';
    }
  }
  
  cout << N << endl;
  
}