#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  
  if (N < 26) {
    set<char> s;
    for (int i = 0; i < N; i++) s.insert(S[i]);
    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (!s.count(ch)) {
        cout << S << ch << endl;
        return 0;
      }
    }
  }
  
  vector<char> t;
  for (int i = 25; i > 0; i--) {
    t.push_back(S[i]);
    
    if (S[i-1] < S[i]) {
      sort(t.begin(), t.end());
      for (char ch : t) {
        if (ch > S[i-1]) {
          S[i-1] = ch;
          cout << S.substr(0,i) << endl;
          return 0;
        }
      }
    }
    
  }
  cout << -1 << endl;
}