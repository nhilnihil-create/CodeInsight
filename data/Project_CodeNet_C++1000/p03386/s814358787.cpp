#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int i, j, x;
  cin >> i >> j >> x;
  for(int r = i; r <= j; r++){
    if(r < i + x || r > j - x) cout << r << endl;
  }

  return 0;
}
