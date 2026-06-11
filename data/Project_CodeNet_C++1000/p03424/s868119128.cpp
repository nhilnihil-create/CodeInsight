#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  char S[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  string ans =  "Three";
  for (int i = 0; i < N; i++) {
      if (S[i] == 'Y') {
        ans ="Four";
      }
  }
  cout << ans << endl;
}
