#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int GCD(int x,int y){
  if(y == 0) return x;
  return GCD(y,x%y);
}

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  int gcd = a[0];
  rep(i,1,n) gcd = GCD(gcd,a[i]);
  cout << gcd << endl;
}