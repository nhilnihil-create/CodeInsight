#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s, t;
  cin >> s >> t;
  reverse(rng(s));
  reverse(rng(t));
  int ssz = s.size();
  int tsz = t.size();
  rep(i,ssz) {
    rep(j,tsz) {
      if(s[i+j]!=t[j]&&s[i+j]!='?') break;
      if(j==tsz-1) {
        rep(k,tsz) {
          s[i+k]=t[k];
        }
        for(int i = 0; i<ssz; i++) {
          if(s[i]=='?') s[i]='a';
        }
        reverse(rng(s));
        cout << s << endl;
        return 0;
      }
    }
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}