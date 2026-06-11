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
  double a[n];
  string s[n];
  double ans = 0;
  rep(i,n){
    cin >> a[i];
    cin >> s[i];
    if(s[i] == "JPY") {
      ans += a[i];
    }
    else {
      ans += 380000 * a[i];
    }
  }
  cout << ans << endl;

  return 0;
}