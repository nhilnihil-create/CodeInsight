#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector <int> x(N+1), y(M+1);
  x[0] = X;
  y[0] = Y;
  for (int i = 1; i <= N; i++) cin >> x[i];
  for (int i = 1; i <= M; i++) cin >> y[i];
  
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  if (x[N] < y[0]) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
