#include <bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >>s;
  int ans=0;
  for(int i=0;i<4;i++){
    if(s[i]=='2') ans++;
  }
  cout <<ans<<'\n';
  return (0);
}