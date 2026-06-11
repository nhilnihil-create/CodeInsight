#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  string s;
  cin >> s;
  ll l=0,r=s.size()-1;
  ll count=0;
  while(l<r) {
    if(s[l]==s[r]) {
      l++;
      r--;
    }
    else if(s[l]=='x') {
      count++;
      l++;
    }
    else if(s[r]=='x') {
      count++;
      r--;
    }
    else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << count << endl;
}