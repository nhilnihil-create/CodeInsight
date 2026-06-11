#include <bits/stdc++.h>
using namespace std;



int main() {
  string S;
  cin >> S;
  
  int K;
  cin >> K;
  
  map<string, bool> dp;

  vector<string> subS;
  
  int N = S.size();
  // j文字目からi個までの部分列を足していく(i=1,2, ..., 5)
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j + i-1< N; j++) {
      string sub = S.substr(j, i);
      if (!dp[S.substr(j, i)]) {
        dp[sub] = true;
        subS.push_back(sub);
      }
    }
  }
  
  sort(subS.begin(), subS.end());
  
  cout << subS[K-1] << endl;
}