#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  string s;  cin >> s;
  ll k;      cin >> k;
  
  int i = 0;
  while(s[i] == '1')
  {
    i++;
    if(i == k)
    {
      cout << 1 << endl;
      return 0;
    }
  }
  
  cout << s[i] << endl;
}