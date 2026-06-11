#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(N);
  vector<int> S(N);
  vector<int> F(N);

  for(int i=1; i<=N-1; i++) {
    cin >> C.at(i) >> S.at(i) >> F.at(i);
  }

  vector<int> time(N+1, 0);
  time[N] = 0;
  for(int i=1; i<=N-1; i++) {
    for(int j=i; j<=N-1; j++) {
      if(time[i] < S[j]) {
        time[i] = S[j];
      } else if(time[i]%F[j] != 0) {
        time[i] += (F[j] - time[i]%F[j]);
      }
      time[i] += C[j];
    }
    cout << time[i] << endl;
  }
  cout << time[N] << endl;

  return 0;
}