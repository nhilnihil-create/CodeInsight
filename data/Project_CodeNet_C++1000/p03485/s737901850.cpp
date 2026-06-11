#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a,b;
  cin >> a >> b;
  b += a;
  if(b % 2) b++;
  cout << b / 2 << endl;
  
  return 0;
}