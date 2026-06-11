#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  ll k;
  cin>>s>>k;
  
  ll cnt=0;
  ll t;
  rep(i,s.size()){
    if(s[i]=='1') cnt++;
    else{
      t=s[i]-'0';
      break;
    }
  }
  if(k<=cnt) cout<<1<<endl;
  else cout<<t<<endl;
    
  return 0;
}