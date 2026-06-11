#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll n; cin >> n;
  long double ans = 0;
  rep(i,n){
    long double m; cin >> m;
    string s; cin >> s;
    if(s == "JPY"){
      ans += m;
    }
    else{
      ans += m*380000;
    }
  }
  cout << fixed << setprecision(10) << ans;
}