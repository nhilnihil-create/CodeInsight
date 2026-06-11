#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a;
  cin >> a;
  int b;
  if ( a % 2) {
    b = a / 2 +1;
  }
else {
  b = a / 2;
}
  cout << a / 2*b << endl;   
  return 0;
}
