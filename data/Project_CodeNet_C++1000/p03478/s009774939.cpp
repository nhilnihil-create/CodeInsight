#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  int B;
  int N;
  int count = 0;
  cin >> N >> A >> B;
  for (int i = 1; i <= N; i++) {
    int C = i / 10000 + (i % 10000) / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10;
    if (A <= C && C <= B) {
      count += i;
    }
  }
  cout << count << endl;  
}
