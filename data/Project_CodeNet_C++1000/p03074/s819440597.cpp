#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  int N, K;
  cin >> N >> K;
  
  string S;
  cin >> S;
  
  
  
  // 1, 0の変わり目の左端を見つける
  
  vector<int> leftbound;
  leftbound.push_back(0);
  leftbound.push_back(0);
  char temp = S[0];
  for (int i = 0; i < N; i++) {
    if (S[i] != temp) {
      leftbound.push_back(i);
      temp = S[i];
    }
  }
  leftbound.push_back(N);
  leftbound.push_back(N);
  
  int ans = 0;
  if (S[0] == '0') {
    if (K >= (leftbound.size()-2)/2) {
      cout << N << endl;
      return 0;
    }
    
    for (int i = 1; i + 2 * K < leftbound.size() ; i += 2) {
      chmax(ans, leftbound[i + 2 * K] - leftbound[i-1]);
    }
    
    
  } else {
    if (K >= (leftbound.size() - 3)/2) {
      cout << N << endl;
      return 0;
    }
    
    for (int i = 2; i + 2 * K < leftbound.size() ; i += 2) {

      chmax(ans, leftbound[i + 2 * K] - leftbound[i-1]);
    }    
  }
  
  cout << ans << endl;


}