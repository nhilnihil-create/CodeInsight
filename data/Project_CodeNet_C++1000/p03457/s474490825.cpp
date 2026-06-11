#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n; cin >>n;
  int t[100100], x[100100], y[100100];
  t[0] = x[0] = y[0] = 0;
  rep(i,n) cin >>t[i+1] >>x[i+1] >>y[i+1];
  bool can = true;
  rep(i,n){
    int dist = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    int dt = t[i+1]-t[i];
    if(dt<dist) can = false;
    if(dt%2!=dist%2) can = false;
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0; 
}
