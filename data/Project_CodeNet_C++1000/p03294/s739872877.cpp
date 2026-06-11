#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
  int n; cin >> n;
  int x;
  ll ans = 0;
  for(int i = 0; i <  n; ++i){
    cin >> x;
    ans += (ll)(x - 1);
  }
  cout << ans << '\n';
}