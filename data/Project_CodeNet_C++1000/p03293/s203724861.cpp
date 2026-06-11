#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  string s,t; cin >> s >> t;
  bool flg = false;
  for(int i = 0; i < s.size(); i++){
    if(s == t) flg = true;
    s = s.back() + s.substr(0,s.size()-1);
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
