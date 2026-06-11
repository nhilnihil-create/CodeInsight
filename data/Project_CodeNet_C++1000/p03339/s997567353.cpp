#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a=0,ans;
  string s;
  cin >> n >> s;
  for(long i=1;i<n;i++) if(s[i]=='E') a++;
  ans=a;
  for(long i=1;i<n;i++) {
    if(s[i-1]=='W') a++;
    if(s[i]=='E') a--;
    ans=min(ans,a);
  }
  cout << ans << endl;
}