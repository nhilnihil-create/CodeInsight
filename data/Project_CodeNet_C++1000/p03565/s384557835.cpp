#include<iostream>
#include<set>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int tins(string s, string t, int k){
  int n=t.size(); if(k+n>s.size())return 0;
  if(df)print(k+n);
  rep(i,n){
    if(df)print(s[i+k],t[i]);
    if(s[i+k]=='?')continue;
    if(s[i+k]!=t[i])return 0;
  }
  return 1;
}

string makeans(string s,string t,int k){
  int n=t.size();
  rep(i,n){
    s[i+k]=t[i];
  }
  n=s.size();
  rep(i,n){
    if(s[i]=='?') s[i]='a';
  }
  if(df)print(s);
  return s;
}

int main(){
  string s,t; cin >>s >>t;
  set<string> st;
  int n=s.size(); 
  rep(i,n){
    if(tins(s,t,i)) st.insert(makeans(s,t,i));
    if(df) print("next");
  }
  if(st.size())print(*st.begin());
  else(print("UNRESTORABLE"));
}
