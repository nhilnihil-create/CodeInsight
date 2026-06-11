#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b;
  c = min(a, b);
  cin >> a >> b;
  c += min(a, b);
  cout << c;
}