#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  int sum = 0;
  cin >> A >> B;
  for (int i = A; i < B+1; i++) {
    if ((i / 10000 == i % 10) && (((i % 10000) / 1000) == ((i % 100) / 10))) sum++;
  }
  cout << sum << endl;  
}