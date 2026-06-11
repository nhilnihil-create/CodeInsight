#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  string s,t,u;
  cin >>s >>t >>u;
  int cnt = 0;
  rep(i,n){
    if(s[i]!=t[i] && t[i]!=u[i] && u[i]!=s[i]) cnt += 2;
    else if(s[i]!=t[i] || t[i]!=u[i] || u[i]!=s[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}