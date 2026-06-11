#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s, t;
  cin >> s >> t;
  
  string ans = "No";
  char c;
  rep(i, s.size()){
    c = s[s.size() - 1];
    for(int j = s.size() - 1; j > 0; j--){
      s[j] = s[j - 1];
    }
    s[0] = c;
    //cout << s << endl;
    if(s == t) ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}