#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=1,mod=1000000007;
  string s;
  vector<long> a(26);
  cin >> n >> s;
  for(long i=0;i<n;i++) a[s[i]-'a']++;
  for(long i=0;i<26;i++) ans=ans*(a[i]+1)%mod;
  ans=(ans+mod-1)%mod;
  cout << ans << endl;
}