#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int sum_all = 0;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    int num = i;
    while (1) {
      sum += num % 10;
      num /= 10;
      if (num == 0) {
        if (A <= sum && sum <= B) sum_all += i;
        break;
      }
    }
  }
  cout << sum_all;
}
  
