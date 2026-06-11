#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int d, n;
  cin >> d >> n;
  int ans;
  if(n == 100) n++;
  if (d == 0){
    ans = n;
  }
  else if(d == 1){
    ans = (n * 100);
  }
  else ans = (n * 10000);
  cout << ans << endl;
  return 0;
}
