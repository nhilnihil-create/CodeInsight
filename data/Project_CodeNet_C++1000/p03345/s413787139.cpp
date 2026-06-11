#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B,C,K;
  cin >> A >> B >> C >> K;
    int N = A - B;
  
  if (K % 2 == 0){
    cout << N << endl;
  }
  else {
    cout << N * (-1) << endl;
  }
}
  
  