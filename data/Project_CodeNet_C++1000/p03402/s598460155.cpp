#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b;
  cin >> a >> b;
  vector<string> ans(100,"");
  for(long i=0;i<100;i++) ans[0]+=".";
  for(long i=0;i<100;i++) ans[99]+="#";
  for(long i=1;i<99;i++) {
    ans[i]=".";
    for(long j=0;j<49;j++) {
      ans[i]+="#";
    }
    for(long j=0;j<49;j++) {
      ans[i]+=".";
    }
    ans[i]+="#";
  }
  a--,b--;
  for(long i=1;b!=0;i+=2) {
    for(long j=1;b!=0&&j!=45;j+=2) {
      ans[i][j+1]='.';
      ans[i+1][j]='.';
      ans[i+1][j+1]='.';
      b--;
    }
  }
  for(long i=98;a!=0;i-=2) {
    for(long j=98;a!=0&&j!=54;j-=2) {
      ans[i][j-1]='#';
      ans[i-1][j]='#';
      ans[i-1][j-1]='#';
      a--;
    }
  }
  cout << "100 100" << endl;
  for(long i=0;i<100;i++) cout << ans[i] << endl;
}