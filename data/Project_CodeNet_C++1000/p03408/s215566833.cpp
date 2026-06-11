#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N), C;
  map<string, int> ss;
  for (int i=0; i<N; i++) {
    cin >> S[i];
    ss[S[i]]++;
  }
  int M;
  cin >> M;
  vector<string> T(M);
  for (int i=0; i<M; i++) {
    cin >> T[i];
    ss[T[i]]--;
  }
  int m=0;
  for (auto p:ss) {
    m=max(m, p.second);
  }
  cout << m << endl;
}
