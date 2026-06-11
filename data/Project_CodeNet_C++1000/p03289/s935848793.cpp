#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main(){
  string s; cin >> s;
  string ans = "AC";
  if(s[0] != 'A') ans = "WA";
  int c = 0;
  for(int i = 2; i < s.size()-1; i++){
    if(s[i] == 'C') c++;
  }
  if(c != 1) ans = "WA";
  c = 0;
  for(int i = 0; i < s.size(); i++){
    if('A' <= s[i] && s[i] <= 'Z') c++;
  }
  if(c != 2) ans = "WA";
  cout << ans << endl;
  return 0;
}
