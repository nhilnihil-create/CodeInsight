#include <bits/stdc++.h>
using namespace std;

string s;
long qq=1,gyakugen,a=0,ab=0,abc=0,mod=1000000007;

long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}

int main() {
  gyakugen=modpow(3,mod-2);
  cin >> s;
  for(long i=0;i<s.size();i++) {
    if(s[i]=='?') qq=qq*3%mod;
  }
  for(long i=0;i<s.size();i++) {
    if(s[i]=='A') {
      a=(a+qq)%mod;
    } else if(s[i]=='B') {
      ab=(ab+a)%mod;
    } else if(s[i]=='C') {
      abc=(abc+ab)%mod;
    } else {
      abc=(abc+(ab*gyakugen%mod))%mod;
      ab=(ab+(a*gyakugen%mod))%mod;
      a=(a+(qq*gyakugen%mod))%mod;
    }
  }
  cout << abc << endl;
}