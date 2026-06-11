#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll N;

ll dfs(string s){
  ll num = 0; 
  ll dig = 1;
  for(ll i = s.size()-1; i >= 0 ;i--){
    num += dig * (s[i] - '0');
    dig *= 10;
  }
  if(N < num) return 0;
  
  ll ret = 0;
  bool san = false;
  bool go = false;
  bool nana = false;
  for(auto ss : s){
    if(ss == '3') san = true;
    if(ss == '5') go = true;
    if(ss == '7') nana = true;
  }
  if(san && go && nana) ret++;
  ret += dfs(s+"3");
  ret += dfs(s+"5");
  ret += dfs(s+"7");
  return ret;
}

int main(){
  cin >> N;
  cout << dfs("3") + dfs("5") + dfs("7") << endl;
  return 0;
}