#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() { 
  int n;
  cin >> n;
  ll ans = 0;
  rep(i, n){
    ll a;
    cin >> a;
    while(a%2==0){
      ans++;
      a /= 2;
    }
  }
  cout << ans << endl;
}


