#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;

  string S;
  cin >> S;

  int R = 0;
  int B = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'R')
      R++;
    else if (S.at(i) == 'B')
      B++;
  }

  if (R > B)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}