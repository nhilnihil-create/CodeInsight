#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int mid = 1; mid < N-1; mid++) {
    bool hit[26][2] = {false};
    for (int l = 0; l < mid; l++) {
      char c = S[l];
      hit[(int)(c-'a')][0] = true;
    }
    for (int r = mid; r < N; r++) {
      char c = S[r];
      hit[(int)(c-'a')][1] = true;
    }
    int same = 0;
    for (int i = 0; i < 26; i++) {
      if (hit[i][0] && hit[i][1]) same++;
    }
    ans = max(ans, same);
  }
  cout << ans << endl;
  return 0;
}
