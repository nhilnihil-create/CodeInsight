#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <iostream>
#include <set>
 
int main(void){
  int n,m;
  cin >> n;
  vector<string> s(n);for(int i=0;i<n;i++) cin >> s[i];
  cin >> m;
  vector<string> t(m);for(int i=0;i<m;i++) cin >> t[i];

  int ans=0;
  for(int i=0;i<n;i++){
    int score=0;
    for(int j=0;j<n;j++) if(s[i]==s[j]) score++;
    for(int j=0;j<m;j++) if(s[i]==t[j]) score--;
    ans = max(ans,score);
  }
  cout << ans << endl;
  return 0;
}