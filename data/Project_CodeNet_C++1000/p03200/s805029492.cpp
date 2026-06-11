#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  long long sum = 0;
  long long count = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'W'){
      sum += i;
      count++;
    }
  }
  for (int i = 0; i < count; i++) {
    sum -= i;
  }
  cout << sum << endl;
}
   