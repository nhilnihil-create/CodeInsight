#include<bits/stdc++.h>
using namespace std;
typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



void solve(){
  string s;
  cin >> s;
  int k;cin >> k;
  set<string> d;
  int n=min(k,(int)s.size());
  for(int i=0;i<s.size();i++){
    for(int j=0;j<=n;j++){
      string t=s.substr(i,j);
      d.insert(t);
    }
  }
  auto itr=d.begin();
  for(int i=0;i<k;i++){
    itr++;
  }
  cout << *itr << endl;
}

int main(){
  solve();
  return 0;
}
