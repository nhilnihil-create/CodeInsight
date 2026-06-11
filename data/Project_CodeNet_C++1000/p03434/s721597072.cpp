#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  priority_queue<int> cards;
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    cards.push(a);
  }
  int Alice = 0, Bob = 0;
  while (!cards.empty()) {
    Alice += cards.top();
    cards.pop();
    if (cards.size() == 0) {
      break;
    }
    if (cards.size() == 1) {
      Bob += cards.top();
      cards.pop();
      break;
    }
    else if (cards.size() != 1) {
      Bob += cards.top();
      cards.pop();
    }
  }
  cout << Alice - Bob << endl;
}