#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  char s[100];
  rep(i, n)
  {
    cin >> s[i];
  }
  rep(j, n)
  {
    if (s[j] == 'Y')
    {
      cout << "Four" << endl;
      exit(0);
    }
  }

  cout << "Three" << endl;
}
