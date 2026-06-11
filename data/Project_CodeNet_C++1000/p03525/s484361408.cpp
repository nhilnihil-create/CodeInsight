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
  ll N;
  cin >> N;
  ll d[55];
  
  for(i=0; i<N; i++) cin >> d[i];
  sort(d, d+N);
  
  
  vector<ll> v; v.push_back(0);
  for(i=0; i<N; i++) {
    if(i&1) v.push_back(d[i]);
    else v.push_back(24-d[i]);
  }
  v.push_back(24);
  sort(v.begin(), v.end());
  
  ll ans=INF;
  for(i=0; i<(ll)v.size()-1; i++) chmin(ans, v[i+1]-v[i]);
  
  pt(ans);
}

