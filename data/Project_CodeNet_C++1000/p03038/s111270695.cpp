#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

template<class Container>
Container reversed(const Container& c) {
  using std::begin;
  using std::end;
  Container r;
  r.reserve(c.size());
  std::reverse_copy(begin(c), end(c), std::back_inserter(r));
  return r;
}

int main(){

  ll n,m;
  cin >> n>> m;
  ll a[n];
  for(int i=0;i<n;i++)cin >> a[i];

  sort(a,a+n);

  vector<vector<ll>> v;
  ll b,c;
  for(int i=0;i<m;i++){
    cin >> b >> c;
    v.push_back({c,b});
  }
  sort(v.begin(),v.end());
  //vector<vector<ll>> v2=reversed(v);
  reverse(v.begin(),v.end());

  vector<ll> d={};

  ll count=0;
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i][1];j++){
      if(count>=n)break;
      d.push_back(v[i][0]);
      count++;
    }
    if(count>n)break;
  }

  for(int i=0;i<n;i++){
    d.push_back(a[i]);
  }

  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());

  ll s=0;
  for(int i=0;i<n;i++)s+=d[i];

  cout << s << endl;

}