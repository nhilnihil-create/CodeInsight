#include <bits/stdc++.h>
using namespace std;

int main () {
  int  N, M, X, Y;
  cin >> N >> M >> X >> Y; 
  
  vector <int> x(N);
  vector <int> y(M);
  for (int i = 0; i < N; i++) cin >> x.at(i);
  for (int i = 0; i < M; i++) cin >> y.at(i);
  sort (x.begin(),x.end());
  sort (y.begin(),y.end());
  int y_min = y.at(0);
  
  bool ans = true;
  if (X >= y_min) ans = false;
  else if (x.at(N-1) >= y_min) ans = false;
  else if (y_min > Y) ans = false;
  if (!ans) cout << "War" << endl;
  else cout << "No War" << endl;
}