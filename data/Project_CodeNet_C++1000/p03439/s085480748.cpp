#include <bits/stdc++.h>
#include <string>
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
  
  ll N;
  cin >> N;
  
  
  pt(0);
  string s0;
  cin >> s0;
  
  if(s0=="Vacant") return 0;
  
  ll l=0, r=N;
  while(l+1<r) {
    ll m=(l+r)/2;
    
    pt(m);
    string sm;
    cin >> sm;
    
    if(sm=="Vacant") return 0;
    
    if(m%2==0) {
      if(sm==s0) l=m;
      else       r=m;
    }else {
      if(sm!=s0) l=m;
      else       r=m;
    }
    
  }
  
}

