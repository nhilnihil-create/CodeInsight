#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define YESNO(i) puts((i)?"YES":"NO");
#define YesNo(i) puts((i)?"Yes":"No");
#define yesno(i) puts((i)?"yes":"no");
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  bool isok=true;
  ll num=0;
  if(s[0]!='A') isok=false;
  if(!islower(s[1])) isok=false;
  for(ll i=2;i<s.length()-1;i++) {
    if(s[i]=='C') num++;
    else {
      if(!islower(s[i])) isok=false;
    }
  }
  if(!islower(s[s.length()-1])) isok=false;
  if(isok) isok=(num==1);
  print(isok?"AC":"WA");
  return 0;
}