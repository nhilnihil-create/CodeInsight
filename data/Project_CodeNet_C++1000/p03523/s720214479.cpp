#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  string s;
  cin >> s;
  string ans;
  int len = s.size();
  bool check = false;
  rep(i, len){
    if(s.at(i) != 'A'){
      ans += s.at(i);
      check = false;
    }
    else if(check || ans == "K" || ans =="KI"){
      cout << "NO" << endl;
      return 0;
    }
    else
      check = true;
    
  }
  if(ans == "KIHBR")
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}