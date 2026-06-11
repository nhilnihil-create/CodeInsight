#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  string s;
  string t;
  cin >> s >> t;
  int n = s.size();
  map<char,char> mps;
  map<char,char> mpt;
  char nc = 'a';
  REP(i,n){
    if(mps.count(s[i])) s[i] = mps[s[i]];
    else{
      mps[s[i]] = nc;
      s[i] = nc;
      nc += 1;
    }
  }

  nc = 'a';
  REP(i,n){
    if(mpt.count(t[i])) t[i] = mpt[t[i]];
    else{
      mpt[t[i]] = nc;
      t[i] = nc;
      nc += 1;
    }
  }
  //cout << s << " " << t << endl;

  if(s == t) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
