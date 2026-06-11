#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n>> m;
  vector<pair<ll,ll>> v;
  for(int i=0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }
  sort(v.begin(),v.end());
  

  ll s=0;
  ll ite=0;
  for(int i=0;i<m;i++){
    if(v[ite].second==0)ite++;
    s+=v[ite].first;
    v[ite].second--;
  }
  cout << s << endl;

}