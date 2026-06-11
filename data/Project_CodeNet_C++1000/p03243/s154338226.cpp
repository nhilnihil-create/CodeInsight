#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  for(;n < 1000; n++){
    if(n % 10 == n / 100 && n / 100 == (n / 10) % 10) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}