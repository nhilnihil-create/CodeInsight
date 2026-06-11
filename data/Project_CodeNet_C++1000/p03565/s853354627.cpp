#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  string s,t; cin >> s >> t;
  bool ok = false;
  for(int i = s.size()-t.size(); 0 <= i; i--){
    bool fit = true;
    rep(j,t.size()){
      if(s[i+j] == '?') continue;
      if(s[i+j] != t[j]) fit = false;
    }
    if(fit){
      rep(j,t.size()) s[i+j] = t[j];
      ok = true;
      break;
    }
  }
  if(ok){
    rep(i,s.size()) if(s[i] == '?') s[i] = 'a';
    cout << s;
  }else{
    cout << "UNRESTORABLE";
  }
  cout << "\n";
  return 0;
}
