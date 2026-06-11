#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans  = 0;
  for(int i = 1; i <= n-1; i++){
    set<char> a;
    string x = s.substr(0,i);
    string y = s.substr(i,n-1);
    rep(j,x.size())rep(k,y.size())if(x.at(j) == y.at(k)) a.insert(x.at(j));
    ans = max((int)a.size(),ans);
  }
  cout << ans << endl;
}
