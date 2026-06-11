#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  char x, y;
  cin >> x >> y;

  // cout << (int)x << endl
  //     << (int)y << endl;

  if ((int)x < (int)y)
    cout << "<";
  else if ((int)x > (int)y)
    cout << ">";
  else
  {
    cout << "=";
  }
}
