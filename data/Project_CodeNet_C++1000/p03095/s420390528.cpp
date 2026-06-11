#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,l[27]={};
  const int mod=1e9+7;
  string s;
  ll ans=1;
  
  cin >> n >> s;
  
  for (i=0;i<n;i++) l[s[i]-'a']++;
  
  for (i=0;i<26;i++) ans=ans*(l[i]+1)%mod;
  
  cout << ans-1 << endl;
  
  return 0;
}