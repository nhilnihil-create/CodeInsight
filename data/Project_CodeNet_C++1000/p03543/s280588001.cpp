#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, n1, n2, n3, n4;
  cin >> N;
  n1 = N /1000;
  n2 = (N % 1000) / 100;
  n3 = (N % 100) / 10;
  n4 = N % 10;
  if(n2 == n3){
    if(n1 == n2 || n3 == n4){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else{
    cout << "No" << endl; 
  }
}