#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << min(min(min(a+c,a+d),b+c),b+d) << endl;
}
