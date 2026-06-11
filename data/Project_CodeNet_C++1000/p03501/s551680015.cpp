#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, A, B;
  cin >> N >> A >> B;
  int pl1 = A * N;
  int pl2 = B;

  if (pl1 > pl2) {
    cout << pl2 << endl;
  }
  else{
  	cout << pl1 << endl;
  }
}