#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int cnt = 0, a = 0, b = 0, ba = 0;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for (int j = 0; j + 1 < S.size(); j++) {
      if (S.at(j) == 'A' && S.at(j + 1) == 'B') cnt++;
    }
    if (S.front() == 'B' && S.back() == 'A') ba++;
    else if (S.front() == 'B') b++;
    else if (S.back() == 'A') a++;
  }
  
  if (a == 0 && b == 0) cnt += max(0, ba - 1);
  else cnt += ba + min(a, b);
  cout << cnt << "\n";
}