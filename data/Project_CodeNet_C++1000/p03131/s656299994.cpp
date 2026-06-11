#include <bits/stdc++.h>
using namespace std;
  
int main() {
  long long K,A,B;
  cin >> K >> A >> B;
  
  if (B-A <= 1 || A >= K+1){
    cout << K + 1 << endl;
  }
  else {
    long long sum = ((K-A+1)/2)*(B-A) + (K-A+1)%2 + A;
    cout << sum << endl;
  }
}