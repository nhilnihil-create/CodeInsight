#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int A, B;
  
  cin >> A >> B;
 
  int count = 0;
  for (int i = A; i < B + 1; i++) {
    if (i % 10 == i / 10000)
      if (i % 100 / 10 == i / 1000 % 10)
        count++;
  }
  
  cout << count << endl;
}