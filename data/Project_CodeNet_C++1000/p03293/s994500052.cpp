#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s,t; cin>>s>>t;
  
  rep(i, s.size()) {
   
   if(s==t) {
     cout<<"Yes";
     return 0;
   }
   
   s = s.back() + s.substr(0, s.size()-1);
  }
  
  cout<<"No";
  return 0;
}