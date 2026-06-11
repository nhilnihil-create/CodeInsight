#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;
  int num = B - A;
  int height = 0;
  for (int i = 0; i < num; i++) height += i;
  cout << height - A << endl;
}
