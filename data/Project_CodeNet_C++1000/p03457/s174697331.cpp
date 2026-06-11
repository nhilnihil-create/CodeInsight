#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int x = 0, y = 0, z = 0;
  int t[n], a[n], b[n];
  rep(i, n) cin >> t[i] >> a[i] >> b[i];
  string s = "Yes";
  rep(i, n){
    int d = abs(x - a[i]) + abs(y - b[i]);
    if((t[i] - z) >= d && (t[i] - z + d) % 2 == 0){
      x = a[i];
      y = b[i];
      z = t[i];
    }
    else {
      s = "No";
      break;
    }
  }
  cout << s << endl;
       

  return 0;
}