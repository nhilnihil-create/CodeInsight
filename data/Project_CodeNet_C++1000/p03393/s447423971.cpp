#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string s;
  cin >> s;
  string ans=s;
  if(s.size()==26) {
    if(!next_permutation(ans.begin(),ans.end())) {
      cout << -1 << endl;
      return 0;
    }
    else {
      ll flag=0;
      for(ll i=0;i<s.size();i++) {
        if(s[i]!=ans[i]) {
          flag=i;
          break;
        }
      }
      ans=ans.substr(0,flag+1);
    }
  }
  else {
    set<char> check;
    for(ll i=0;i<s.size();i++) {
      check.insert(s[i]);
    }
    for(ll i=0;i<26;i++) {
      if(!check.count(char('a'+i))) {
        ans=s+char('a'+i);
        break;
      }
    }
  }
  cout << ans << endl;
}