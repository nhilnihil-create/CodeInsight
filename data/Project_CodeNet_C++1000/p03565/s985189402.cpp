#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int 
main() 
{

  string s, t; cin >> s >> t;

  for(int i = s.size() - 1; t.size() - 1 <= i ; i--){
    int count = 0;
    int tmpindex = t.size() - 1;
    for(int k =  i; 0 <= tmpindex; k--){
     if(s[k] == t[tmpindex] || '?' == s[k]) count++;
     tmpindex--;
    }
    if(count == t.size()){
      int tmpindex2 = t.size() - 1;
      for(int l = i; 0 <= tmpindex2; l--){
        s[l] = t[tmpindex2];
        tmpindex2--;
      }
      rep(i, 0, s.size()){
        if(s[i] == '?') s[i] = 'a';
      }
      cout << s << endl;
      return 0;
    }
  }

  cout << "UNRESTORABLE" << endl;

  return 0;
}


