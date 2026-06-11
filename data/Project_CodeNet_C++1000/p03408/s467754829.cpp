#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> T(M);
  for (int i = 0; i < M; i++) {
    cin >> T.at(i);
  }
  
  int ret = 0, tmp_ret = 0;
  string tmp_str;
  for (int i = 0; i < S.size(); i++) {
    tmp_ret = 0;
    tmp_str = S.at(i);
    for (int j = 0; j < S.size(); j++) {
      if (tmp_str == S.at(j)) {
        tmp_ret++;
      }
    }
    for (int j = 0; j < T.size(); j++) {
      if (tmp_str == T.at(j)) {
        tmp_ret--;
      }
    }
    ret = max(ret, tmp_ret);
  }
  cout << ret << endl;
}
