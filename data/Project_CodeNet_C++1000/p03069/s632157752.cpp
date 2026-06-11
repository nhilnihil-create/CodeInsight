#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=9999999999;
  string s;
  cin >> n >> s;
  vector<long> wcost(n+1),bcost(n+1);
  for(long i=1;i<=n;i++) {
    if(s[i-1]=='.') wcost[i]=wcost[i-1];
    else wcost[i]=wcost[i-1]+1;
  }
  for(long i=n-1;i>=0;i--) {
    if(s[i]=='#') bcost[i]=bcost[i+1];
    else bcost[i]=bcost[i+1]+1;
  }
  for(long i=0;i<=n;i++) ans=min(ans,wcost[i]+bcost[i]);
  cout << ans << endl;
}