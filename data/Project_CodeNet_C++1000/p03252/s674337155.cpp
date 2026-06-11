#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

int
main() 
{
  string s, t;cin >> s >> t;
  map<char, char>dics;
  map<char, char>dict;

  rep(i, 0, s.size()){
    char indexs = s[i];
    if(dics.count(indexs) == 0){
      dics[indexs] = t[i];
    } else {
      if(dics[indexs] == t[i])continue;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
 
  rep(i, 0, t.size()){
    char indext = t[i];
    if(dict.count(indext) == 0){
      dict[indext] = s[i];
    } else {
      if(dict[indext] == s[i])continue;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}


