#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
typedef pii point;
using namespace std;

int main(){
  ll n; cin>>n;
  vi a(n); REP(i,n) cin>>a[i];
  if(n==2){
    cout<<max(a[0],a[1])<<' '<<min(a[0],a[1])<<endl;
    return 0;
  }
  sort(a.begin(),a.end());
  vpii v;
  REP(i,n) v.push_back(make_pair(min(a[i],a[n-1]-a[i]),a[i]));
  sort(v.begin(),v.end());
  cout<<a[n-1]<<' '<<v[n-1].second<<endl;
}
