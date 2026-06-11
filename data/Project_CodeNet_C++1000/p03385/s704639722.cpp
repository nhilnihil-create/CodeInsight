#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  string s;
  cin >> s;
  vector<bool> v(3, false);
  rep(i,3){
    if(s[i]=='a'){
      v[0] = true;
    }
    if(s[i]=='b'){
      v[1] = true;
    }
    if(s[i]=='c'){
      v[2] = true;
    }
  }
  if(v[0]&&v[1]&&v[2]) cout <<  "Yes" << endl;
  else cout <<  "No" << endl;
}      
       