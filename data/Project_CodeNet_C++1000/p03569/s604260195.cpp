#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;

  int head = 0;
  int tail = S.size() - 1;
  int ans = 0;
  while(head < tail) {
    if(S[head] == S[tail]) {
      head++;
      tail--;
      continue;
    }
    if(S[head] == 'x' && S[tail] != 'x') {
      head++;
      ans++;
      continue;
    }
    if(S[tail] == 'x' && S[head] != 'x') {
      tail--;
      ans++;
      continue;
    }
    cout << -1 << endl;
    return 0;
  }

  cout << ans << endl;
  return 0;
}