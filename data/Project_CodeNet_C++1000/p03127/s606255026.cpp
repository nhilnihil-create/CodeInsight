#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int gcd(int a, int b){
  if (b ==  0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a.at(i);
  int ans = a.at(0);
  REP(i,1,n) ans = gcd(ans, a.at(i));
  cout << ans << endl;
}
