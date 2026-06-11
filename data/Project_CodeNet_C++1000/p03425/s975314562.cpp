#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i<n; i++) cin >> S[i];
  long long  M = 0, A=0, R=0, C=0, H=0;
  for (int i = 0; i < n; i++) {
    if (S[i][0] == 'M') M++;
    if(S[i][0] == 'A') A++;
    if(S[i][0] == 'R') R++;
    if(S[i][0] == 'C') C++;
    if(S[i][0] == 'H') H++;
  }
  long long cnt = M * A * R + M * A * C + M * A * H + M * R * C + M * R * H + M * C * H + A * R * C + A * R * H + R * C * H + A * C * H;
  cout << cnt << endl;
  return 0;
}