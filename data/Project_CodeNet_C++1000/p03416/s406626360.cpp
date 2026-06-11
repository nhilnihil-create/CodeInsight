#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, i, cnt = 0, a, b, c, d;
  cin >> A >> B;

  for ( i = A; i < B + 1; i++)
  {
    a = i / 10000;
    b = i / 1000 % 10;
    c = i / 10 % 10;
    d = i % 10;
    if (a == d && b == c)
    {
      cnt ++;
    }
  }

  cout << cnt << endl;
}