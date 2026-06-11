#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  string s;
  cin >> s;
  set<char> a;
  for(int i=0; i<s.size(); i++) {
    a.insert(s[i]);
  }
  if(s.size()<26) {
    for(char i='a'; i<='z'; i++) {
      if(!a.count(i)) {
        cout << s << i << endl;
        return 0;
      }
    }
  } else {
    set<char> b;
    for(int i=s.size(); i>=0; i--) {
      for(char c=s[i]; c<='z'; c++) {
        if(b.count(c)) {
          cout << s.substr(0,i) << c << endl;
          return 0;
        }
      }
      b.insert(s[i]);
    }
    cout << -1 << endl;
    return 0;
  }
}
