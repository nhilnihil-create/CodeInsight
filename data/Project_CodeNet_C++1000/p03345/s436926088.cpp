#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A, B, C, K;
  cin >> A >> B >> C >> K;
  if(K % 2 == 0){
    cout << A - B << endl;
  }
  if(K % 2 == 1){
    cout << B - A << endl;
  }
  return 0;
}