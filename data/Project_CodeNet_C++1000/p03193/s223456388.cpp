#include <bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,h,w;
  cin >>n>>h>>w;
  int ans=0;
  for(int i=0;i<n;i++){
    int a,b;
    cin >>a>>b;
    if(h<=a&&w<=b) ans++;
  }
  cout <<ans<<'\n';
  return (0);
}