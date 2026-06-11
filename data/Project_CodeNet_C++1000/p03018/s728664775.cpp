#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  string t=regex_replace(s,regex("BC"),"X");
  ll l=t.length(),counta=0,ans=0;
  rep(i,l) {
    if(t[i]=='A') counta+=1;
    else if(t[i]=='X') ans+=counta;
    else counta=0;
  }
  print(ans);
  return 0;
}