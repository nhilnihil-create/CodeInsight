#include <bits/stdc++.h>
using namespace std;

void do_ex_2(int N) {
  for (int i = 0; i <= N / 4; i++) {
    for (int j = 0; j <= N/7; j++) {
      if (i * 4 + j * 7 == N) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}

int main(int, char**) {
  int N;
  cin >> N;
  do_ex_2(N);
  return 0;
}
