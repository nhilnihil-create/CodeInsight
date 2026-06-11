#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int amount = N * A;
  
  if (amount <= B) {
  	cout << amount << endl; // 真
  } else {
  	cout << B << endl; // 偽
  }
}