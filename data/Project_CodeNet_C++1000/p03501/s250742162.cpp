#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  
  int plan1Fee = a * n;
  int plan2Fee = b;
  
  if (plan1Fee < plan2Fee)
  {
    cout << plan1Fee;
  }
  else
  {
    cout << plan2Fee;
  }
}