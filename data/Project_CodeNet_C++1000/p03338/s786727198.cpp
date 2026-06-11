#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  string s;
  cin >> n >> s;
  for(long i=1;i<n;i++) {
    vector<bool> x(26);
    vector<bool> y(26);
    long a=0;
    for(long j=0;j<i;j++) x[s[j]-'a']=true;
    for(long j=i;j<n;j++) y[s[j]-'a']=true;
    for(long j=0;j<26;j++) if(x[j]&&y[j]) a++;
    ans=max(ans,a);
  }
  cout << ans << endl;
}