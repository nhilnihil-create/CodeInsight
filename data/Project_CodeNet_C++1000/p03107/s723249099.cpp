#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int a,b; a=0; b=0;
  string s; cin >> s;
  rep(i,s.size()){
    if(s[i] == '0') a++;
    else b++;
  }
  
  cout << min(a,b)*2 << endl;
  
}