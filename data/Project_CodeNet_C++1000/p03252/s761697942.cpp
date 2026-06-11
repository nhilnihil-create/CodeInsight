#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007
 
 
 
int main(){
 
  string s,t;
  cin >> s >> t;
  map<char,char> mp;
  rep(i,s.size())mp[s[i]] = t[i];
  for(char c = 'a';c <= 'z';c++){
    for(char ch = 'a';ch <= 'z';ch++){
      if(mp.count(c) == 0 || mp.count(ch) == 0 || c == ch)continue;
      if(mp[c] == mp[ch]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  rep(i,s.size())s[i] = mp[s[i]];
  cout << (s == t ? "Yes" : "No") << endl;
 
 
 
 
 
  return 0;
}