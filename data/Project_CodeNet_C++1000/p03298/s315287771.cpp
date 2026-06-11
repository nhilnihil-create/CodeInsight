#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=0;
  string s,l,r;
  cin >> n >> s;
  l=s.substr(0,n);
  r=s.substr(n,n);
  string red,blue;
  map<string, int> mp;
  for(int bit=0;bit<(1 << n);bit++){
    red="";
    blue="";
    for(int i=0;i<n;i++){
      if(bit & (1 << i)){
        red+=l[i];
      }else{
        blue+=l[i];
      }
    }
    string t=red+","+blue;
    mp[t]++;
  }
  for(int bit=0;bit<(1 << n);bit++){
    red="";
    blue="";
    for(int i=0;i<n;i++){
      if(bit & (1 << i)){
        red+=r[i];
      }else{
        blue+=r[i];
      }
    }
    reverse(red.begin(), red.end());
    reverse(blue.begin(), blue.end());
    string t=blue+","+red;
    ans+=mp[t];
  }
  cout << ans << endl;
  return 0;
}
