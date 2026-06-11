#include <bits/stdc++.h>
using namespace std;

long h,w;
string ans="Yes";
vector<string> s(60);

bool check(long i,long j) {
  if(s[i][j]=='.') return false;
  if(i!=0) if(s[i-1][j]=='#') return false;
  if(i!=h-1) if(s[i+1][j]=='#') return false;
  if(j!=0) if(s[i][j-1]=='#') return false;
  if(j!=w-1) if(s[i][j+1]=='#') return false;
  return true;
}

int main() {
  cin >> h >> w;
  for(long i=0;i<h;i++) cin >> s[i];
  for(long i=0;i<h;i++) {
    for(long j=0;j<w;j++) {
      if(check(i,j)) ans="No";
    }
  }
  cout << ans << endl;
}