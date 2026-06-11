#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n;
  cin >> n;

  map<char,ll> name;

  std::vector<string> s(n);
  string a;
  rep(i,n){
    cin >> s.at(i);
    a=s.at(i);
    name[a.at(0)]+=1;
  }

  ll mar,mac,mah,mrc,mrh,mch,arc,arh,ach,rch;

  mar=name['M']*name['A']*name['R'];
  mac=name['M']*name['A']*name['C'];
  mah=name['M']*name['A']*name['H'];
  mrc=name['M']*name['R']*name['C'];
  mrh=name['M']*name['R']*name['H'];
  mch=name['M']*name['C']*name['H'];
  arc=name['A']*name['R']*name['C'];
  arh=name['A']*name['R']*name['H'];
  ach=name['A']*name['C']*name['H'];
  rch=name['R']*name['C']*name['H'];

  ll sum=mar+mac+mah+mrc+mrh+mch+arc+arh+ach+rch;


  cout << sum << endl;


  }
