#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  string s;
  cin >> s;
  ll n=s.size();
  ll coA=0;
  ll ans=0;
  for(ll i=0;i<n;++i){
    if(s[i]=='A'){
      coA++;
    }else if(s[i]=='B' && s[i+1]=='C'){
      ans+=coA;
    }else if(i>0 && s[i-1]=='B' && s[i]=='C'){
      continue;
    }else{
      coA=0;
    }
  }
  cout << ans << endl;
  return 0;
}
