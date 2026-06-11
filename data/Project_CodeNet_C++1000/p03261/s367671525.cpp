#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  int n;
  cin >> n;
  vector<string>s(n);
  map<string, int>mp;
  bool OK = true;
  rep(i,n) cin >> s[i];
  rep(i,n){
    mp[s[i]]++;
  }
  if(mp.size()!=n) OK = false;
  for (int i = 1; i < (n); ++i) {
    if(s[i-1].back() != s[i].front()) OK = false;
  }
  if(OK) puts("Yes");
  else puts("No");
}