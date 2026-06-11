#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  priority_queue<int> A;
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    A.push(num);
  }
  
  int alice = 0, bob = 0;
  bool a_turn = true;
  while (!(A.empty())) {
    if (a_turn) {
      alice += A.top();
      A.pop();
      a_turn = false;
    } else {
      bob += A.top();
      A.pop();
      a_turn = true;
    }
  }
  
  cout << (alice - bob) << endl;  
}