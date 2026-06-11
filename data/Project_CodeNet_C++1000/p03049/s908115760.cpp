#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,fb=0,ea=0,fbea=0;
  cin >> n;
  vector<string> s(n);
  for(long i=0;i<n;i++) cin >> s[i];
  for(long i=0;i<n;i++) for(long j=0;j<s[i].size()-1;j++) if(s[i][j]=='A'&&s[i][j+1]=='B') ans++;
  for(long i=0;i<n;i++) {
    if(s[i][0]=='B') {
      if(s[i].back()=='A') {
        fbea++;
      } else {
        fb++;
      }
    } else if(s[i].back()=='A') {
      ea++;
    }
  }
  if(fbea>=2)ans+=fbea-1;
  if((fb>0||ea>0)&&fbea>=1) ans++;
  ans+=min(fb,ea);
  cout << ans << endl;
}