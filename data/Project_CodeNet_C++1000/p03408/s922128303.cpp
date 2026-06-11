#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  vector<string>s(N);
  vector<string>t(M);
  for (int i = 0; i < N; i++) {
    cin >> s.at(i);
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> t.at(i);
  }
  
  vector<int>count(N,0);
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (s.at(i) == s.at(j)){
        count.at(i)++;
      }
      if (j == N-1){
        for (int k = 0; k < M; k++) {
          if (s.at(i) == t.at(k)){
            count.at(i)--;
          }
        }
      }
    }
  }
  sort(count.begin(), count.end());
  
  if (count.at(N-1) < 0){
    cout << 0 << endl;
  }
  else {
     cout << count.at(N-1) << endl;
  }
}
  