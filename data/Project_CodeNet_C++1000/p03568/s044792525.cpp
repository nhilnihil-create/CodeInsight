#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int counta = 1;
  int countb = 1;
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    counta *= 3;
    if (A.at(i) % 2 == 0){
      countb *= 2;
    }
  }
  cout << counta - countb << endl;
}
  