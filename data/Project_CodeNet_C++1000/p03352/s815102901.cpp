#include <bits/stdc++.h>

using namespace std;


int main() {
  int x;
  cin >> x;
  
  vector<bool> exp(1000); 
  exp[1] = true;
  for(int i=2; i<=1000; ++i){
    for(int j=2; pow(i, j)<=1000; ++j){
      exp[(int)pow(i, j)] = true;
    }
  }
  
  for(int i=x; i>=0; --i){
    if(exp[i]){
      cout << i << endl;
      return 0;
    }
  }
  
}
