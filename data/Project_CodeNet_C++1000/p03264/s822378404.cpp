#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K;
  cin >> K;
  
  if (K%2 == 0){
    cout << K*K/4 << endl;
  }
  else {
    cout << (K/2)*((K+1)/2) << endl;
  }
}