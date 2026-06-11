#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int C = 0;
  for (int i = A; i <= B; i++){
    int s1 = i / 10000 % 10;
    int s2 = i / 1000 % 10;
    int s4 = i / 10 % 10;
    int s5 = i % 10;
    if (s1 == s5 && s2 == s4){
      C += 1;
    }
  }
  cout << C << endl;
}