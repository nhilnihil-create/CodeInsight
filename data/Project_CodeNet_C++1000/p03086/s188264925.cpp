#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
  string S; cin >> S;
  int N = S.size();
  int start_i = -1, max_l = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] != 'A' && S[i] != 'C' && S[i] != 'G' && S[i] != 'T') start_i = i;
    max_l = max(max_l, i - start_i);
  }
  cout << max_l << endl;
}