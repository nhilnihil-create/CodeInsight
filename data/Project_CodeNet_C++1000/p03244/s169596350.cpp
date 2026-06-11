#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define moca(a, s, b) a=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


ll cnt[MAX*100]={};
int main(void) {
  ll i, j, k;
  
  ll N;
  cin >> N;
  ll a[MAX];
  
  map<ll, ll> mp[2];
  for(i=0; i<N; i++) {
    cin >> a[i];
    
    mp[i&1][a[i]]++;
  }
  mp[0][-1]=0;
  mp[1][-1]=0;
  
  priority_queue<pll> qu[2];
  for(i=0; i<2; i++) {
    for(auto it=mp[i].begin(); it!=mp[i].end(); it++) {
      qu[i].push(pll(it->sc, it->ft));
    }
  }
  
  pll p=qu[0].top(); qu[0].pop();
  pll q=qu[1].top(); qu[1].pop();
  
  if(p.sc==q.sc) {
    pll p1=qu[0].top(), q1=qu[1].top();
    pt(min(N-p.ft-q1.ft, N-p1.ft-q.ft));
  }else {
    pt(N-p.ft-q.ft);
  }
  
  
}
 
 
