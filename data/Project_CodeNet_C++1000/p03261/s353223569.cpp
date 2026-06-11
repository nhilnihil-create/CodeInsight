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

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<string> ws;
  ws.emplace(s);
  bool flag = true;
  rep(i,0,n-1) {
    string w;
    cin >> w;
    if (ws.count(w)) flag = false;
    if (s[len(s)-1] != w[0]) flag = false;
    ws.emplace(w);
    s = w;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
