#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for(int i = 1; i < n; ++i){
    int cnt = 0;
    for(char c='a'; c <= 'z' ;++c){
      bool left = false, right=false;
      rep(j,i){
        if(s[j]==c) left=true;
      }
      for(int j = i; j<n ; ++j){
        if(s[j]==c) right=true;
      }
      if(left&&right) cnt++;
    }
    if(ans<cnt) ans=cnt;
  }
  cout << ans << endl;
  return 0;
}