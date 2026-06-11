#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int sum = 0;
  
  for (int i = 1; i <= N; i++) {
    int amount = i;
    int c5 = amount / 10000;
    amount %= 10000;
    int c4 = amount / 1000;
    amount %= 1000;
    int c3 = amount / 100;
    amount %= 100;
    int c2 = amount / 10;
    amount %= 10;
    int c1 = amount;
    
    int c = c5 + c4 + c3 + c2 + c1;
    if (A <= c && c <= B) {
      sum += i;
    }
  }
  
  cout << sum << endl;
}