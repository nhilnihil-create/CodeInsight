#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  sort(s.begin(),s.end());
  int kind = 0;
  for(int i = 1; i <= n; i++){
    if(s[i] != s[i-1]) kind++;
  }
  if(kind==3) cout << "Three" << endl;
  if(kind==4) cout << "Four" << endl;
}