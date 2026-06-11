#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,K;
  cin >> A >> B >> K;
  
  vector<int>C(100,1);
  for (int i = 1; i <= 100; i++) {
    if (A%i == 0 && B%i == 0){
      C.at(i-1) = i;
    }
  }
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  cout << C.at(K-1) << endl;
}
  