#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}



int main() {
  int N;
  ll acnt=0,ans=0;
  string S;
  cin >> S;
  N=S.size();
  rep(i,N-1) {
    if (S[i]=='A') acnt++;
    else if (S[i]=='B') {
      if (S[i+1]=='C') {
        ans += acnt;
        i++;
      }
      else acnt=0;
    }
    else acnt=0;
  }
  cout << ans << endl;
}