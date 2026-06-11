#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll euclidean_gcd(ll a, ll b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}


int main() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  bool ok = true;
  if(s[a]!='-') ok = false;
  rep(i,a){
    if(!(s[i]>='0'&&s[i]<='9')) ok = false;
  }
  for(int i = a+1; i < s.size(); ++i){
    if(!(s[i]>='0'&&s[i]<='9')) ok = false;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}