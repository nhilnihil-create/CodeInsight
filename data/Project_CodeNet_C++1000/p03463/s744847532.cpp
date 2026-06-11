#include "bits/stdc++.h"
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B ;
  if((B-A) & 1){
    cout << "Borys" ;
  }else{
    cout << "Alice";
  }
  cout << endl;
  return 0;
}