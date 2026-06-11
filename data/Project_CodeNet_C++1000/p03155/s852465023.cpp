#include <bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,h,w;
  cin >>n>>h>>w;
  h=n-h+1;
  w=n-w+1;
  cout <<h*w<<'\n';
  return (0);
}