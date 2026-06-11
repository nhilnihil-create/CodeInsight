#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  string s; cin >> s;
  int ans1=0; int ans2=0;
  rep(i,s.size()){
    if(i%2 == 0){
      if(s[i] == '0') ans1++;
      else ans2++;
    }
    else{
      if(s[i] == '1') ans1++;
      else ans2++;
    }
  }
  
  cout << min(ans1, ans2) << endl;
}