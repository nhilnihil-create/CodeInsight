#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> Nmin(M);
  vector<int> Nmax(M);
  
  for (int i = 0; i < M; i++) {
    cin >> Nmin.at(i) >> Nmax.at(i);
  }
  
  int idmin = 1;
  int idmax = N;
  
  for (int i = 0; i < M; i++) {
    idmin = max(idmin, Nmin.at(i));
    idmax = min(idmax, Nmax.at(i));
  }
  
  int result = idmax - idmin + 1;
  if (result < 0) {
    result = 0;
  }
  
  cout << result << endl;
  
  return 0;
}