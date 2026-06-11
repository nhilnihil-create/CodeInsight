#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
  Int N;
  cin >> N;
  vector<string> S(N);
  vector<int> leng(N);
  set<string> ss;
  
  rep(i,N) {
    cin >> S[i];
    leng[i] = S[i].size();
    auto ite = ss.find(S[i]);
    if (ite != ss.end()) {
      cout << "No" << endl;
      return 0;
    }
    else ss.insert(S[i]);
  }
  
  bool flag = true;
  rep1(i,N-1) {
    if (S[i-1][leng[i-1]-1] != S[i][0]) flag = false;
  }
  
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
