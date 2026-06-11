#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;


int main(){
  string s;
  cin >> s;
  int sz = s.size();
  vector<pair<char, int>> A(26);
  if(sz<26){
      int p = 0;
    for(char c = 'a'; c<='z'; c++){
      A[p].first = c;
      A[p].second = 0;
      p++;
    }
    rep(i, sz){
      rep(j, 26){
        if(s.at(i)==A[j].first) {A[j].second = 1; break;}
      }
    }
    rep(i, 26){
      if(A[i].second==0) {s = s+A[i].first; break;}
    }
    cout << s << endl;
  }
  
  else {
    //vector<char> P;
    if(s=="zyxwvutsrqponmlkjihgfedcba") cout << -1 << endl;
    else {
      int r, g, e;
      vector<char> P;
      char v;
      for(r=25; r>=0; r--){
        if(s.at(r)<s.at(r-1)){
          P.push_back(s.at(r));
          //s.pop();
        }
        else {P.push_back(s.at(r));v=s.at(r-1); g=r; break;}
      }
    
    string o = "";
    int l=P.size();
    char m;  
    sort(P.begin(), P.end());  
    rep(i, l){
      if(P.at(i)>v) {m = P.at(i); break;}
    }  
    //cout << m << endl;  
    rep(i, g){
      if(i==g-1) o = o+m;
      else o = o+s.at(i); 
    }
    cout << o << endl;  
    }
  }
}