#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define ss substr

int main() {
  string s, t;
  cin >> s >> t;
  int n = len(s);
  map<string, set<string>> a, b;
  rep(i,0,n) {
    a[s.ss(i,1)].emplace(t.ss(i,1));
    if (len(a[s.ss(i,1)]) >= 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  rep(i,0,n) {
    b[t.ss(i,1)].emplace(s.ss(i,1));
    if (len(b[t.ss(i,1)]) >= 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}