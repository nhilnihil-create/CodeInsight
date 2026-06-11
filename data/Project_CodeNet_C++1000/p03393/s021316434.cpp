#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  string s; cin >>s;
  int n = s.size();
  if(n<26){
    map<char, int> mp;
    rep(i,n) mp[s[i]]++;
    for(char c = 'a'; c<='z'; c++){
      if(mp[c]==0) {
        cout << s << c << endl;
        return 0;
      }
    }
  }
  if(s=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
    return 0;
  }
  string t = s;
  next_permutation(t.begin(), t.end());
  rep(i,26){
    cout << t[i];
    if(s[i]!=t[i]) break;
  }
  cout << endl;
  return 0;
}