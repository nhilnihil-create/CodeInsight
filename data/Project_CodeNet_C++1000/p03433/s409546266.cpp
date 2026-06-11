#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0, A = 0;
  cin >> N >> A;
  int a = N / 500;
  a *= 500;
  if( N - a <= A ){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}