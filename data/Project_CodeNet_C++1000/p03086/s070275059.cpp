#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string S;
  cin >> S;
  int N = S.size();

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp_length = 0;
    for (int j = i; j < N; j++) {
      if (S[j] == 'A' || S[j] == 'C' || S[j] == 'G' || S[j] == 'T') {
        tmp_length++;
      } else {
        break;
      }   
    }
    ans = max(ans, tmp_length);
  }
  
  cout << ans << endl;
  return 0;
}
