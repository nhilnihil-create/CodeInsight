#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int A;
  cin >> N >> A;
  while ( N > 499){
  N = N - 500;
  }
  
  if (N < A + 1){
    cout << "Yes";
  }else{
    cout << "No" ;
  }
}