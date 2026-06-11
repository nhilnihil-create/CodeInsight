#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;

using namespace std;

  int tt;

int main(){

  cin >> tt;
  while(tt--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b > a) {
      cout << "No\n";
      continue;
    }
    if(b > d) {
      cout << "No\n";
      continue;
    }
    if(c >= b){
      cout << "Yes\n";
      continue;
    }
    ll g = __gcd(b, d);
    if(b - g + a % g > c) {
      cout << "No\n";
    }
    else{
      cout << "Yes\n";
    }
  }

return 0;
}
