#include <bits/stdc++.h>
using namespace std;
pair<int, int> edge(int x_1, int y_1, int x_2, int y_2) {
  int x = x_2 + y_1 - y_2;
  int y = y_2 - x_1 + x_2;
  pair<int, int> p = make_pair(x, y);
  return p;
}
int main() {
  int x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;
  cin >> x_1 >> y_1 >> x_2 >> y_2;
  pair<int, int> p = edge(x_1, y_1, x_2, y_2);
  x_3 = p.first;
  y_3 = p.second;
  pair<int, int> q = edge(x_2, y_2, x_3, y_3);
  x_4 = q.first;
  y_4 = q.second;
  cout << x_3 << " " <<  y_3 << " " << x_4 << " " << y_4 << endl;
}