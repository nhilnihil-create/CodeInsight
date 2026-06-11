#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

string s,ans;
int k;
void dfs(string t){
  if(k==0) return;
  if(t.size()>0){
    bool ok = true;
    for(int i = 0; i+t.size()<=s.size(); ++i ){
      ok = true;
      rep(j,t.size()){
        if(s[i+j]!=t[j]){
          ok = false;
          break;
        }
      }
      if(ok){
        if(--k==0) ans = t;
        break;
      }
    }
    if(!ok) return;
  }
  if(t.size()<s.size()){
    for(char c = 'a'; c<='z'; ++c){
      string nt = t+c;
      dfs(nt);
    }
  }
}
int main() {
  cin >> s >> k;
  string t = "";
  dfs(t);
  cout << ans << endl;
}
