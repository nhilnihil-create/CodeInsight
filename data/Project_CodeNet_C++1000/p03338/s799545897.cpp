#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for(int i = 1; i < n-1; i++){
    vector<char> a,b;
    for(int j = 0; j < n; j++){
      if(i < j){
        a.push_back(s[j]);
      }else{
        b.push_back(s[j]);
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      a.erase(unique(a.begin(), a.end()), a.end());
      b.erase(unique(b.begin(), b.end()), b.end());
      int cnt = 0;
      for(char c: a){
        for(char ch: b){
          if(c == ch){
            cnt++;
            break;
          }
        }
      }
      ans = max(cnt, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
