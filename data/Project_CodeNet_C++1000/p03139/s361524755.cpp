#include <bits/stdc++.h>
using namespace std;

int main (){
  int N, A, B;
  cin >> N >> A >> B;
  
  if (A >= B){
    cout << B;
  }
  else {
    cout << A;
  }
  cout << " ";
  if (N >= A + B){
    cout << 0;
  }
  else {
    cout << A + B - N;
  }
}