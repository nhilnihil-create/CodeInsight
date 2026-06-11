#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int m=0;
  for (int i=0; i<N; i++) {
    set<char> E;
    for (int j=0; j<i; j++) {
      for (int k=i; k<N; k++) {
        if (S[j]==S[k]) {
          E.insert(S[j]);
        }
      }
    }
    m=max(m, (int)E.size());
  }
  cout << m << endl;
 }
