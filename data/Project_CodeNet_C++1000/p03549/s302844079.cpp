#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,m; cin >>n >>m;
  int x = (1900*m+100*(n-m));
  rep(i,m) x*=2;
  cout << x << endl;
  return 0;
}