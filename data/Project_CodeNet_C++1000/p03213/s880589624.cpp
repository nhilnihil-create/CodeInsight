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
static const ll LOGN=55;


map<ll, ll> prime;
void factrization(ll n) {
  for(ll i=2; i*i<=n; i++) {
    while(n%i==0) {
      prime[i]++;
      n/=i;
    }
  }
  
  if(n>1) prime[n]++;
}


ll N;

int main(void) {
  cin >> N;
  ll i;
  ll cnt[111]={};
  for(i=2; i<=N; i++) factrization(i);
  
  for(auto it=prime.begin(); it!=prime.end(); it++) {
    cnt[it->second]++;
  }
  
  
  ll sc[111]={};
  for(i=99; i>=0; i--) {
    sc[i]=sc[i+1]+cnt[i];
  }
  
  ll ans=0;
  ans+=sc[74];
  ans+=sc[24]*(sc[2]-1);
  ans+=sc[14]*(sc[4]-1);
  ans+=sc[4]*(sc[4]-1)/2*(sc[2]-2);
  
  pt(ans);
}




