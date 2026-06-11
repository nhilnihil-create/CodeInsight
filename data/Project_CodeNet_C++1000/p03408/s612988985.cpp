#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, j = 0, f = 0, g = 0;
  string w;
  cin >> N;
  vector<string> B(N);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  cin >> M;
  vector<string> R(M);
  for (int i = 0; i < M; i++) cin >> R.at(i);
  
  while (j < N){
    w = B.at(j);
    for (int i = j; i < N; i++) if (w == B.at(i)) f++;
    for (int i = 0; i < M; i++) if (w == R.at(i)) f--;
    if (f > g) g = f;
    f = 0;
    j++;
  }
  
  cout << g << endl;
}