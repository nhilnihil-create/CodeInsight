#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  long long A;
  
  if (N%2 == 0){
    A = N;
  }
  else{
    A = N*2;
  }
  cout << A << endl;
}

