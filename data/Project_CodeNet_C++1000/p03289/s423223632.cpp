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
  string s; cin >> s;
  bool flg = true;
  if(s[0] != 'A') flg = false;
  int c = 0;
  for(int i = 2; i < s.size()-1; i++){
    if(s[i] == 'C') c++;
  }
  if(c != 1) flg = false;
  c = 0;
  for(int i = 0; i < s.size(); i++){
    if('A' <= s[i] && s[i] <= 'Z') c++;
  }
  if(c != 2) flg = false;
  if(flg) cout << "AC" << endl;
  else cout << "WA" << endl;
  return 0;
}
