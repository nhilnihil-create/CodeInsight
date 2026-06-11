#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int allb = 0;
  for(int i=0; i<n; ++i) if(s[i] == '.') ++allb;
  int ans = allb;
  for(int i=0; i<n; ++i){
    if(s[i] == '#') ++allb;
    else --allb;
    ans = min(ans, allb);
  }
  cout << ans << endl;
}