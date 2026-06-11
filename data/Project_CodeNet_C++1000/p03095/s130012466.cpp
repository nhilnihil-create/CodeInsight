#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  string S;
  cin >> N >> S;
  vector<int>count(26,0);
  
  for (int i = 0; i < N; i++) {
    int M = S.at(i) - '0';
    M -= 49;
    count.at(M)++;
  }
  
  long long ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= (count.at(i) + 1);
    ans %= 1000000007;
  }
  if (ans == 0){
    cout << 100000006 << endl;
  }
  else {
    cout << ans -1 << endl;
  }
}
    