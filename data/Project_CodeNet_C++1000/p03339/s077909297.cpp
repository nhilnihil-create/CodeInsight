#include <bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N; string S; cin >> S;
  vector<int> DPw(N), DPe(N);
  DPw.at(0) = 0; DPe.at(N - 1) = 0;
  for(int i = 1; i < N; i++) {
    DPw.at(i) = DPw.at(i - 1) + ((S.at(i - 1) == 'W') ? 1 : 0);
    DPe.at(N - 1 - i) = DPe.at(N - i) + ((S.at(N - i) == 'E') ? 1 : 0);
  }
  int x = 1000000;
  for(int i = 0; i < N; i++) {
    x = min(x, (DPw.at(i) + DPe.at(i)));
  }
  cout << x << endl;
}