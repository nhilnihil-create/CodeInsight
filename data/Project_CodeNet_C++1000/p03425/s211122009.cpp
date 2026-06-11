#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  ll m = 0,a = 0,r = 0,c = 0,h = 0;
  rep(i,0,n){
    string s;
    cin >> s;
    if(s[0] == 'M') m++;
    if(s[0] == 'A') a++;
    if(s[0] == 'R') r++;
    if(s[0] == 'C') c++;
    if(s[0] == 'H') h++;
  }
  ll ans = 0;
  ans += m*a*r;
  ans += m*a*c;
  ans += m*a*h;
  ans += m*r*c;
  ans += m*r*h;
  ans += m*c*h;
  ans += a*r*c;
  ans += a*r*h;
  ans += a*c*h;
  ans += r*c*h;
  cout << ans << endl;
}