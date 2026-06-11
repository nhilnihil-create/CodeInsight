#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int amount = A * B;
  
  if (amount % 2 == 0) {
 	 cout << "Even" << endl; // 真
  } else {
 	 cout << "Odd" << endl; // 偽
  }
}