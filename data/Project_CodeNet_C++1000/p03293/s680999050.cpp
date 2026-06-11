#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  string s,t;
  cin >> s >> t;
 
  bool flag = false;
  int n = s.size();
  rep(i,n){
    for(int i = n-1; i > 0; i--) swap(s[i],s[i-1]);
    if(s==t) flag = true;
  }
  if(flag) cout << "Yes" << endl;
  if(!flag)cout << "No" << endl;
}