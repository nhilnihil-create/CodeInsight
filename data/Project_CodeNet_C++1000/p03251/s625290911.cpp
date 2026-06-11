#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M, X, Y;
vector<int> x, y;

int main() {
  cin >> N >> M >> X >> Y;
  x.resize(N);
  y.resize(M);
  for (int i = 0; i < N; i++)
    cin >> x[i];
  for (int i = 0; i < M; i++)
    cin >> y[i];

  int x_max = *max_element(x.begin(), x.end());
  int y_min = *min_element(y.begin(), y.end());
  if (x_max < y_min && x_max < Y && X < y_min)
    cout << "No War" << endl;
  else
    cout << "War" << endl;

  return 0;
}
