#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  int a, b;
  cin >> a >> b >> s;
  string ans = "Yes";
  rep(i, s.size()){
    //cout << s[i] << i << endl;;
    if(i == a){
      if(s[i] != '-') {
      	ans = "No";
      }
      else continue;
    }
    if(s[i] < '0' || s[i] > '9') ans = "No";
    //cout << ans << endl;
  }
  cout << ans << endl;

  return 0;
}
