#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  string S;
  cin >> S;
  int K;
  cin >> K;
  set<string> s;
  for(int i = 0; i < S.size(); i++){
    string tmp;
    for(int j = 0; i + j < S.size() && j < 5; j++){
      tmp += S[i+j];
      s.insert(tmp);
    }
  }
  for(int i = 0; i < K - 1; i++){
    string tmp = *s.begin();
    s.erase(tmp);
  }
  cout << *begin(s) <<endl;
}
