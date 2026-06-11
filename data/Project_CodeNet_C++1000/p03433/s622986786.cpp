#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
    cin >> n;
  int a;
    cin >> a;
  if((n - a) % 500 == 0)
  {
    cout << "Yes" << endl;
  }
  else if(n - a <= 0)
  {
    cout << "Yes" << endl;
  }
  else if(n % 500 - a <= 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
  