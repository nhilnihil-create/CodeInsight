#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int n, flg = 0;
  cin >> n;
  
  rep(i, n)
  {
    char c;
    cin >> c;
    if(c == 'Y')
    {
      flg = 1;
      break;
    }

  }

  if(flg)
    cout << "Four" <<endl;
  else
    cout << "Three" <<endl;
  
}
