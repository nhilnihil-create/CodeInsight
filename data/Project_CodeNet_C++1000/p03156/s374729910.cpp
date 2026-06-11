#include <bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,a,b;
  cin >>n>>a>>b;
  int m[3]={};
  while(n--){
    int p;cin >>p;
    if(p<=a) m[0]++;
    else if(p<=b) m[1]++;
    else m[2]++;
  }
  cout <<min({m[0],m[1],m[2]})<<'\n';
  return (0);
}