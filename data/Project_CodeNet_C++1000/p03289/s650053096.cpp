#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef long double ld;

int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  if(s[0]!='A') {
    cout << "WA" << endl;
    return 0;
  }
  int flg = 0;
  for(int i = 1;i < s.length();i++){
   	if(s[i] == 'C' && 2 <= i && i <= s.length()-2){
      flg++;
    }
    else if('a' > (int)s[i] || (int)s[i] > 'z'){
      cout << "WA" << endl;
      return 0;
    }
  }
  if(flg != 1) {
    cout << "WA" << endl;
    return 0;
  }
  cout << "AC" << endl;
  return 0;
}