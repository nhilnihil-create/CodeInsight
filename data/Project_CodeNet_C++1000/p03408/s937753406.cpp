#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> S(N);
  for (int i=0; i<N; i++) {
    cin >> S.at(i);
  }
  
  int M;
  cin >> M;
  
  vector<string> T(M);
  for (int j=0; j<M; j++) {
    cin >> T.at(j);
  }
  
  int b=0, r=0;
  int ans=0;
  
  for (int i=0; i<N; i++) {
    b=0, r=0;
    for (int j=0; j<N; j++) {
      if (S.at(i)==S.at(j)) {
        b++;
      }
    }
    for (int k=0; k<M; k++) {
      if (S.at(i)==T.at(k)) {
        r++;
      }
    }
    if (ans<b-r) {
      ans=b-r;
    }
  }
  cout << ans << endl;
}