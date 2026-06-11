#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,S;
  M =0;
  cin >> N;
  S = N -1;
  vector<int>P(N);
  for(int i = 0;i < N;i++) cin >> P[i];
  sort(P.begin(), P.end());
  P[S] /= 2;
  for(int i = 0;i < N;i++) M += P[i];
  cout << M <<endl;
}