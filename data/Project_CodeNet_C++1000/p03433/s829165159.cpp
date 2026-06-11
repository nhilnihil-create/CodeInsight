#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, x, y;
  cin >> N >> A;
  x = N % 500;

  if(x <= A){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  } 
}