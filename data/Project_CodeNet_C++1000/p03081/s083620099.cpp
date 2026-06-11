#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<char>t(q),d(q);
  rep(i,q)cin>>t[i]>>d[i];
  s='?'+s+'?';
  int l=0,r=n+1;
  for(int i=q-1;i>=0;i--){
    if(d[i]=='R'){
      if(s[r-1]==t[i])r--;
      if(s[l]==t[i])l--;
    }
    else{
      if(s[r]==t[i])r++;
      if(s[l+1]==t[i])l++;
    }
  }
  cout<<r-l-1<<endl;
  return(0);
}
