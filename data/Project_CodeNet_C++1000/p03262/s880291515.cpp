#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int gcd(int x, int y){
  if(x>y) swap(x,y);
  if(x==0) return y;
  return gcd(x,y%x);
}

int main(){
  int n,x; cin >>n >>x;
  vector<int> t(n);
  rep(i,n) {
    cin >>t[i];
    t[i] = abs(t[i]-x);
  }
  int ans = t[0];
  rep(i,n){
    ans = gcd(ans,t[i]);
  }
  cout << ans << endl;
  return 0; 
}