#include <bits/stdc++.h>
using namespace std;

uint64_t getLucasNumber(int number)
{
  if( number == 0 ){
    return 2;
  }
  else if( number == 1 ){
    return 1;
  }
  else{
    vector<uint64_t> tmp(2);
    tmp.at(0) = 2;
    tmp.at(1) = 1;
    for( int i=2; i<=number-1; i++ ){
      if( (i % 2) == 0 ){
        tmp.at(0) += tmp.at(1);
      }
      else{
        tmp.at(1) += tmp.at(0);
      }
    }
    return ( tmp.at(0) + tmp.at(1) );
  }
}

int main() {
  int N;
  cin >> N;
  
  uint64_t lucasNumber = getLucasNumber(N);
  
  cout << lucasNumber << endl;
}
