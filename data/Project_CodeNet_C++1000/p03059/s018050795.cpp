#include<bits/stdc++.h>
#define rep(i,n) for<int i=0; i<(n); ++i>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,t;
  double tall;
  cin >> a >> b >> t;
  int ans=0; 
  tall = t+0.5;
  ans = (tall/a);
  ans = ans * b;
  cout << ans << endl;
}