#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int N, a, b, i, j, num=0, judge=0, sub;
  cin >> N >> a >> b;
  sub = abs(a - b);
  if (sub%2)
    judge = 1;
  else
    judge = -1;
  if (judge == -1)
    cout << "Alice" << endl;
  else if (judge == 1)
    cout << "Borys" << endl;
  else if (judge == 0)
    cout << "Draw" << endl;
  return 0;
}
