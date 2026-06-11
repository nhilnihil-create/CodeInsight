#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
int main() {
  int a, b;
  vector<int> ab(3);
  cin >> a >> b;
  ab[0] = a+b;
  ab[1] = a-b;
  ab[2] = a*b;
  auto ans = max_element(ALL(ab));
  cout << *ans << endl;
  return 0;
}