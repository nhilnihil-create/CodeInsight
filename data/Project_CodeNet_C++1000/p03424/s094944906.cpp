#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int n; cin>>n;
  vector<char> s(n); rep(i,n) cin>>s[i];
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  cout<<(s.size()==3?"Three":"Four");
}