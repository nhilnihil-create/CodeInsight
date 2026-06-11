#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

bool func(int n, int a, int b){
  int now = 0;
  while(n){
    now += n%10;
    n /= 10;
  }
  if(a <= now && now <= b) return true;
  return false;
}

int main(){
  int a,b; cin >> a >> b;
  string s; cin >> s;
  vector<char> chk(10);
  rep(i,10) chk[i] = i+'0';

  bool flg = true;
  for(int i = 0; i < a; i++){
    for(int j = 0; j < 10; j++){
      if(chk[j] == s[i]) break;
      if(j == 9) flg = false;
    }
  }
  if(s[a] != '-') flg = false;
  for(int i = a+1; i < a+b+1; i++){
    for(int j = 0; j < 10; j++){
      if(chk[j] == s[i]) break;
      if(j == 9) flg = false;
    }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
