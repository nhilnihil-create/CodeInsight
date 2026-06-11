#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=200020;

int main() {
  string s;
  ll N;
  cin>>N>>s;
  ll ans=MAX,cnt=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='.'){
      cnt++;
    }
  }
  ans=cnt;
  for(int i=0;i<s.size();i++){
    if(s[i]=='.'){
      cnt--;
    }
    if(s[i]=='#'){
      cnt++;
    }
    ans=min(ans,cnt);
  }
  cout<<ans;
  
}
