#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

int main() {
  bool abc[26];
  rep(i, 0, 26) abc[i] = 0;

  string s; cin >> s;
  rep(i, 0, s.size()){
    abc[s[i]-'a'] = true;
  }
  if(s.size() < 26){
    rep(i, 0, 26){
    if(abc[i]) continue;
      else{
        cout << s << char('a'+i) << endl;
        return 0;
      }
    }
  }
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
    return 0;
  }
  string t = s;
  next_permutation(ALL(s));
  rep(i, 0, 26){
    if(s[i]==t[i]) cout << s[i];
    else{
      cout << s[i] << endl;
      return 0;
    }
  }
  
  return 0;
}
