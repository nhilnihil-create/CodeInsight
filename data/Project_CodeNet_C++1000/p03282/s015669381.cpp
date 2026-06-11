#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  string s;
  cin >> s;
  ll k;
  cin >> k;
  k--;
  int n=s.size();
  int ans=1;
  for(int i=0;i<n;++i){
    if(i<=k && s[i]!='1'){
      ans=int(s[i]-'0');
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
