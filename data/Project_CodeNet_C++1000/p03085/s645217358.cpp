#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  char c;
  cin >> c;
  if(c == 'A') cout << 'T' << endl;
  else if(c == 'T') cout << 'A' << endl;
  else if(c == 'G') cout << 'C' << endl;
  else cout << 'G' << endl;
  return 0;
}
