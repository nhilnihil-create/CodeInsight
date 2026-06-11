#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  string s;
  cin >>n >>s;
  int red = 0, blue = 0;
  rep(i,n){
    if(s[i]=='R') red++;
    else blue++;
  }
  if(red>blue) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}