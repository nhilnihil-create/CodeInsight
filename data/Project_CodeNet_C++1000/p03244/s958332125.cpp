#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)


int main() {
  ll n;
  cin>>n;
  vector<ll> v(n);
  vector<ll> a(100005,0);
  vector<ll> b(100005,0);

  rep(i,n){
    cin>>v[i];
    if(i%2==0)a[v[i]]++;
    else b[v[i]]++;
  }
  vector<P>ap;
  vector<P>bp;
  rep(i,100005){
    if (a[i]!=0){
        ap.push_back(make_pair(a[i],i));
    }
    if (b[i]!=0){
        bp.push_back(make_pair(b[i],i));
    }
  }
  ap.push_back(make_pair(0,-1));
  bp.push_back(make_pair(0,-1));
  ap.push_back(make_pair(0,-2));
  bp.push_back(make_pair(0,-2));

  sort(ap.rbegin(),ap.rend());
  sort(bp.rbegin(),bp.rend());
  ll a1=ap[0].first;
  ll b1=bp[0].first;
ll ans;
  if (ap[0].second==bp[0].second){
    ll a2=ap[1].first;
    ll b2=bp[1].first;
    ans=min(n-a1-b2,n-a2-b1);

  }
  else{
    ans=n-a1-b1;
  }

cout<<ans;


}
