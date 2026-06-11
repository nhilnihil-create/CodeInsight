#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int plan_a = n * a;
  int plan_b = b;
  if(plan_a < plan_b)
    cout << plan_a << endl;
  else
    cout << plan_b << endl;
}
