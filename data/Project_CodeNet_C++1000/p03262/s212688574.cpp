#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int gcd(int a, int b){
  if (b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
  int n, X;
  cin >> n >> X;

  vi x(n+1);
  rep(i,n) cin >> x.at(i);
  x.at(n) = X;
  sort(x.begin(),x.end());

  vi diff(n);
  rep(i,n){
    diff.at(i) = abs(x.at(i+1) - x.at(i));
  }

  int ans = diff.at(0);
  REP(i,1,n){
    ans = gcd(ans, diff.at(i));
  }
  cout << ans << endl;
}
