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
  string s,t;
  cin >> s >> t;
  string ans = "No";
  for(int i = 0; i < s.size(); i++){
    if(s == t) ans = "Yes";
    s = s.back() + s.substr(0,s.size()-1);
  }
  cout << ans << endl;
  return 0;
}
