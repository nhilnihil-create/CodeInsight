#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int sum = 0, total = 0;
  for(int c = 0; X-c >= 0 || Y-c >= 0; c++)
  {
    if(c == 0) sum = A*X + B*Y;
    else
    {
      total = A*max(0,X-c) + B*max(0,Y-c) + C*c*2;
      sum = min(sum, total);
    }
  }
  cout << sum << endl;
}