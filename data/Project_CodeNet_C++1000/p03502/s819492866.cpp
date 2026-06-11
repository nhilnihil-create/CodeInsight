#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,calN,Sum=0;
  cin >> N;
  calN = N;
  
  rep(i,9){
  Sum += calN % 10;
  calN /= 10;
  }
  
  if (N % Sum == 0){
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}
