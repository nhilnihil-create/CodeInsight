#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long

int x[MX];
int y[MX];
int a;
signed main() {
  int a;
  cin >> a;
  set<char> s;
  rep(i,a){
    char c;
    cin >> c;
    s.insert(c);

  }
  if(s.size()==4)cout << "Four" << endl;
  else cout << "Three" << endl;
  return 0;
}
