#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;




int main(void) {
  string str;
  cin >> str;
  ll i;
  string s="";
  
  for(i=0; i<str.size(); i++) {
    if(str[i]=='B' && str[i+1]=='C') {
      s.push_back('D');
      i++;
    }else {
      s.push_back(str[i]);
    }
  }
  
  ll ans=0;
  ll t=0;
  for(i=(ll)s.size()-1; i>=0; i--) {
    if(s[i]=='A') ans+=t;
    else if(s[i]=='D') t++;
    else t=0;
  }
  
  pt(ans);
}



