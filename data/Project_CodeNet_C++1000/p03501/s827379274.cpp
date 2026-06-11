#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  1<=n<=20;
  1<=a<=100;
  1<=b<=2000;
  cin >> n>>a>>b;

  if (n*a>=b) {
    cout <<b<< endl;
  }
  else {
    cout << n*a << endl;
  }
}
