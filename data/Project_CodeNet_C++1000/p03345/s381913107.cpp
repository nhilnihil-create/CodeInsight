#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  long long A, B, C;
  cin >> A >> B >> C;
  long long K;
  cin >> K;
  if (K % 2 == 0){
    cout << A - B << endl;
  } else {
    cout << B - A << endl;
  }
}