#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N , A;
  
  cin >> N >> A;
  
  if ( N % 500 <= A ){
    cout << " Yes " << endl;
  }
  if ( N % 500 > A ){
    cout << " No " << endl;
  }
}