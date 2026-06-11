#include <iostream>
#include <cstring>

using namespace std;



int a[200005];
int dp[1 << 26];
const int INF = 1e9;

int main() {
  string s;
  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    a[i+1] = (1 << (s[i] - 'a')) ^ a[i];
    //  cout << a[i+1] << endl;
  }

  for(int i = 0; i < (1 << 26); i++) dp[i] = INF;

  dp[0] = 0;

  int tmp;
  for(int i = 1; i <= s.size(); i++) {
    tmp = dp[a[i]];
    for(int j = 0; j < 26; j++) {
      int s = (1 << j);
      tmp = min(tmp,dp[a[i] ^ s]);
    }
    dp[a[i]] = min(dp[a[i]],tmp + 1);
    //  cout << a[i] <<"   "<<dp[a[i]] << endl;
  }
  cout << tmp + 1 << endl;
}
