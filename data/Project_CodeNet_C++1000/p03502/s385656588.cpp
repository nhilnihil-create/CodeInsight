#include <bits/stdc++.h>
using namespace std;

int set_sum(int N) {
  int sum = 0;
  while(N>0) {
    sum += N % 10;
    N /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;
  bool answer = false;
  
  int sum = set_sum(N);
  if(N % sum == 0) answer = true;

  if(answer == true) cout << "Yes" << endl;
  if(answer == false) cout << "No" << endl;
}