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

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


int main(void) {
  ll i, j, k;
  string s;
  cin >> s;
  
  ll cnt=0;
  string t="";
  for(i=0; i<s.size(); i++) {
    if(s[i]=='A') cnt++;
    else t+=s[i];
  }
  
  ll f=1;
  if(t!="KIHBR") f=0;
  if(cnt>4) f=0;
  
  for(i=0; i<s.size(); i++) {
    string s2=s.substr(i, 2);
    
    if(s2=="KA") f=0;
    if(s2=="IA") f=0;
    if(s2=="AA") f=0;
  }
  
  if(f) pt("YES");
  else pt("NO");
  
}

