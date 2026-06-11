#include <bits/stdc++.h>
using namespace std;

int main(){
  //input
  int64_t n;
  cin >> n;
  
  //declare array
  vector<int64_t> luc(n+1);
  luc.at(0) = 2;
  luc.at(1) = 1;
  for (int i = 2; i < n+1; i++){
    luc.at(i) = luc.at(i-1) + luc.at(i-2);
  }
  
  //output
  cout << luc.at(n) << endl;
}