#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  for(int i=1; i<round(sqrt(n)); ++i){
    if(n%i == 0){
      ans += n/i -1;
    }
  }
  cout << ans << endl;
}